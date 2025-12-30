# 🏦 Bank Management System - Version 1 (V1)

This project is the final practical application of **Level 7 (Algorithms & Problem Solving Level 3)** within the "Programming Advices" roadmap. The project aims to build a comprehensive system for managing client data with persistent storage using files.

---

## 🎯 Core Concept & Logic
The core logic is based on **Managing Data Lifecycle** between permanent storage (Files) and temporary memory (Program):
* **Database:** Data is stored in a simple text file named `Clients.text`.
* **Data Structuring (Structs):** Each text line from the file is converted into a **Data Structure (Struct)** of type `sClientInfo` for easier manipulation within the program.
* **Dynamic Processing (Vectors):** All structs are stored in a `vector<sClientInfo>` to facilitate efficient searching, updating, and fast deletion without data size constraints.

---

## 🛠️ Technical Implementation

The source code focuses on applying the following concepts with high precision:

### 1. String Processing
* **Splitting:** Developed the `SplitvString` function to parse text lines using the `#//#` separator.
* **Conversion:** Built `ConvertLineToRecord` to transform strings into data-filled structs, and `ConvertRecordToLine` to reverse the process for saving.

### 2. Data Operations
* **Logical Deletion (Mark for Delete):** Implemented a professional logic that flags records for deletion within the vector using the `MarkForDelete = true` property.
* **Database Synchronization:** The file is completely rewritten from the vector while skipping flagged records, ensuring data integrity.
* **Validation:** Added checks to ensure the "Account Number" is unique and not duplicated when adding new clients.

### 3. UI & Organization
* **Structured Menus:** Used `enum enMenueChoose` to manage main menu options, ensuring clean and maintainable code.
* **Output Formatting:** Utilized the `iomanip` library to ensure client data tables are displayed in a professional, aligned manner.

---

## 🚀 Project Update (Extension)
I have developed an upgraded version of this project with added Transactions and logic validation. 
**Check out the extended version here:** [Bank Management System - Extended Edition (V2)](https://github.com/ammmrrr18-cloud/Project-2---Bank-Extension---Level-7)

---

## 📁 Repository Content
* **My-Solution:** Contains my personal implementation (Source `.cpp` and Solution `.sln` files).
* **Instructor-Solution:** Contains the model solution by Dr. Mohammed Abu-Hadhoud for review and technical comparison.

---
*📌 "Attention to detail is what distinguishes a coder from a software engineer."*
