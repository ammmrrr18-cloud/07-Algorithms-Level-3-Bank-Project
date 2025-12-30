
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <conio.h> 


using namespace std;

const string ClientsFileName = "Clients.text";

enum enMenueChoose { ClientList = 1, NewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Exit = 6 };
struct sClientInfo
{
    string AccountNumber;
    string PIN;
    string Name;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
};


vector<string> SplitvString(string St1, string delim)
{
    vector <string> vString;
    short Pos = 0;
    string sWord = "";
    while ((Pos = St1.find(delim)) != string::npos)
    {
        sWord = St1.substr(0, Pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        St1.erase(0, Pos + delim.length());
    }
    if (St1 != "")
    {
        vString.push_back(St1);
    }
    return vString;
}


void ShowMainMenueScreen()
{
    cout << "==========================================\n";
    cout << "\t\tMainMenueScreen\n";
    cout << "==========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";
    cout << "==========================================\n";

}

enMenueChoose ReadMainMenueScreen()
{
    short UserChoose = 0;
    do
    {
        cout << "Choose,What do you want to do? [1 To 6]?";
        cin >> UserChoose;

    } while (UserChoose < 1 || UserChoose>6);

    return (enMenueChoose)UserChoose;
}

sClientInfo ConvertLineToRecord(string strClientInfoLine, string Seperator = "#//#")
{
    sClientInfo Client;
    vector<string>vClientData;

    vClientData = SplitvString(strClientInfoLine, Seperator);

    /*   if (vClientData.size() < 5) {

           Client.AccountNumber = "INVALID";
           return Client;
       }*/

    Client.AccountNumber = vClientData[0];
    Client.PIN = vClientData[1];
    Client.Name = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

vector<sClientInfo> LoadClientsDataFromFile(string FileName)
{


    vector<sClientInfo> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);


    if (MyFile.is_open())
    {
        string Line = "";
        sClientInfo Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }

    return vClients;
}

void PrintClientRecord(sClientInfo Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PIN;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.PhoneNumber;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";



    cin >> AccountNumber;

    return AccountNumber;
}

string Read_ClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter an account number ?";

    cin >> AccountNumber;

    return AccountNumber;
}

bool FindClientAccountNumber(string AccountNumber, vector<sClientInfo>& vClients, sClientInfo& Client)
{

    for (sClientInfo& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

sClientInfo ReadNewClientInfo(sClientInfo& ClientInfo)
{

    cout << "\nEnter PinCode? ";
    getline(cin >> ws, ClientInfo.PIN);

    cout << "\nEnter Name? ";
    getline(cin, ClientInfo.Name);

    cout << "\nEnter Phone? ";
    getline(cin, ClientInfo.PhoneNumber);

    cout << "\nEnter AccountBalance? ";
    cin >> ClientInfo.AccountBalance;

    return ClientInfo;
}

string ConvertRecordToLine(sClientInfo& ClientInfo, string Dilem = "#//#")
{
    string Text = "";

    Text += ClientInfo.AccountNumber + Dilem;
    Text += ClientInfo.PIN + Dilem;
    Text += ClientInfo.Name + Dilem;
    Text += ClientInfo.PhoneNumber + Dilem;
    Text += to_string(ClientInfo.AccountBalance);

    return Text;
}

void SaveClientDataToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }

}


void PrintClientCard(sClientInfo& ClientInfo)
{
    cout << "\nThe following are the client details:\n\n";

    cout << setw(17) << "AccountNumber   : " << ClientInfo.AccountNumber << endl;
    cout << setw(17) << "pin Code        : " << ClientInfo.PIN << endl;
    cout << setw(17) << "Name            : " << ClientInfo.Name << endl;
    cout << setw(17) << "Phone           : " << ClientInfo.PhoneNumber << endl;
    cout << setw(17) << "Account Balance : " << ClientInfo.AccountBalance << endl;

}

void PrintAllClientsData(vector<sClientInfo>& vClients)
{

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n\n";
    cout << "----------------------------------------------------------------------------------------------------------------\n\n";
    cout << "| " << left << setw(15) << "Account Number ";
    cout << "| " << left << setw(10) << "Pin Code ";
    cout << "| " << left << setw(40) << "Client Name ";
    cout << "| " << left << setw(12) << "Phone ";
    cout << "| " << left << setw(8) << "Balance Account ";
    cout << "\n\n----------------------------------------------------------------------------------------------------------------\n\n";


    for (sClientInfo& Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n\n----------------------------------------------------------------------------------------------------------------\n\n";



}

sClientInfo ChangeClientRecord(string AccountNumber)
{
    sClientInfo ClientInfo;

    ClientInfo.AccountNumber = AccountNumber;

    cout << "\nEnter PinCode?";
    getline(cin >> ws, ClientInfo.PIN);

    cout << "\nEnter Name?";
    getline(cin, ClientInfo.Name);

    cout << "\nEnter Phone?";
    getline(cin, ClientInfo.PhoneNumber);

    cout << "\nEnter AccountBalance?";
    cin >> ClientInfo.AccountBalance;


    return ClientInfo;

}

void SaveClientsDataToFile(string FileName, vector<sClientInfo>& vClients)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (sClientInfo& C : vClients)
        {
            string DataLine = "";
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

}

void AddNewClient(vector<sClientInfo>& vClients)
{

    sClientInfo Client;
    bool AccountExists = false;
    string AccountNumber = "";

    cout << "\nPlease enter an account number ?";
    do {
        AccountNumber = ReadClientAccountNumber();
        AccountExists = FindClientAccountNumber(AccountNumber, vClients, Client);

        if (AccountExists)
        {
            cout << "\nClient With [" << AccountNumber << "] is already exists,Enter another Account Number?";
        }

    } while (AccountExists);

    Client.AccountNumber = AccountNumber;

    Client = ReadNewClientInfo(Client);
    SaveClientDataToFile(ClientsFileName, ConvertRecordToLine(Client));

}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClientInfo>& vClients)
{


    sClientInfo Client;
    char Answer = 'n';

    if (FindClientAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\nAre you sure that you want to update this Client? (Y or N)?";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            for (sClientInfo& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(ClientsFileName, vClients);

            cout << "\nClient Updated Successfully\n";
            return true;
        }
        else
        {
            cout << "\nClient was not Updated.\n";
            return false;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not found !\n\n";
        return false;
    }


}

void AddClients(vector<sClientInfo>& vClients)
{
    char AddMore = 'y';
    do
    {
        system("cls");
        cout << "_______________________________________\n";
        cout << "Adding New Clients Screen\n";
        cout << "_______________________________________\n";

        cout << "\nAdding New Client:\n";




        AddNewClient(vClients);

        cout << "\nClient added successfully,do you want to add more clients (Y or N) ?";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');


}


bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClientInfo>& vClients)
{
    for (sClientInfo& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClientInfo>& vClients)
{

    sClientInfo Client;
    char Answer = 'n';


    if (FindClientAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);


        cout << "\nAre you sure that you want to delete this Client\n";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);

            vClients = LoadClientsDataFromFile(ClientsFileName);

            cout << "\nClient deleted Successfully\n";

            return true;
        }
        else
        {
            cout << "\nClient was not deleted.\n";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not found !\n\n";
    }
    return false;
}

void ExitProject()
{
    cout << "--------------------------------------\n";
    cout << "\tProgram Ends :-)\n";
    cout << "--------------------------------------\n";
}

void PressAnyKeyToContinue()
{
    cout << "\nPress any key to go back to Main Menue...";
    _getch();
    system("cls");
}


void PerformMainMenueOption(vector<sClientInfo>& vClients)
{
    sClientInfo Client;
    enMenueChoose Choose;
    string AccountNumber = "";

    do {

        ShowMainMenueScreen();
        Choose = ReadMainMenueScreen();

        switch (Choose)
        {

        case enMenueChoose::ClientList:
            system("cls");
            PrintAllClientsData(vClients);
            PressAnyKeyToContinue();
            break;

        case enMenueChoose::NewClient:
            AddClients(vClients);
            PressAnyKeyToContinue();
            break;

        case enMenueChoose::DeleteClient:
            system("cls");
            DeleteClientByAccountNumber(Read_ClientAccountNumber(), vClients);
            PressAnyKeyToContinue();
            break;

        case enMenueChoose::UpdateClient:
            system("cls");
            UpdateClientByAccountNumber(Read_ClientAccountNumber(), vClients);
            PressAnyKeyToContinue();
            break;

        case enMenueChoose::FindClient:
            system("cls");

            AccountNumber = Read_ClientAccountNumber();
            if (!FindClientAccountNumber(AccountNumber, vClients, Client))
            {
                cout << "\nClient With [" << AccountNumber << "] is Not Found !" << endl;
            }
            else
            {
                PrintClientCard(Client);
            }

            PressAnyKeyToContinue();
            break;

        case enMenueChoose::Exit:
            system("cls");
            ExitProject();
            PressAnyKeyToContinue();
            break;

        }

    } while (Choose != 6);
}

void StartBank()
{
    vector<sClientInfo>vClients = LoadClientsDataFromFile(ClientsFileName);
    PerformMainMenueOption(vClients);
}


int main()
{

    StartBank();


    return 0;
}
