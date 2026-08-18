#  Personal-Diary-Management-system-CSE115

A personal diary management system developed in C, allowing users to add, edit, delete, and search entries while utilizing file handling for data storage and encryption for privacy.

# 📖 Personal Diary Management System
This is our first-semester project: a professional and robust implementation of a Personal Diary Management System, developed entirely in C.The project features user registration and login authentication structured diary entry management (add, view, search, edit, delete) duplicate ID and username validation and file handling. The implementation emphasizes performance, data integrity, maintainability, and clean software design principles.

## 👥 Group Information

| SL | FULL-NAME | STUDENT-ID |
| :---: | :--- | :---: |
| 01 | **Muhammad Fahimul Hoque** | 2621584042 |
| 02 | **Aadila Zaheen** |2622214042  |
| 03 | **Samia Meharin Lisa** | 2623705042 |
| 04 | **MD. Ashrafuzzaman** | 2625096042 |

Course: **CSE115** | Section: **04** | Faculty: **MSRb**

## 🚀 Key Features

* **User Authentication & Registration:** Registration system with password confirmation and duplicate username prevention.
* **Full Entry Lifecycle (CRUD):** Create, view, edit, and delete diary entries identified by unique serial numbers.
* **Serial Search System:** Fast lookup to locate individual entries by their unique serial number.
* **File Handling:** Automatic saving and loading of user credentials (`users.dat`) and diary entries (`entries.dat`) using C binary file I/O.
* **Duplicate Serial Validation:** In-memory checks to prevent duplicate entry serial IDs.
* **Clean Console Interface:** Menu-driven terminal UI with console buffer management (`system("cls")`).

# 📋 Menu Navigation

* `1` — Add Entry
* `2` — View My Entries
* `3` — Search My Entry by Serial
* `4` — Edit An Entry
* `5` — Delete Entry
* `6` — Log out

## 📁 Repository Architecture

This repository strictly follows the course layout rules:

* `main.c` — The primary entry point containing core authentication, menu handling, and file storage logic.
* `requirements.txt` — Environment specifications, C standard requirements, and system library dependencies.
* `README.md` — Repository documentation and execution guide (this file).

* `📁data/`—   
   * `users.dat` — Local binary data storage for registered user credentials.

   * `entries.dat`—  Local binary data storage for diary entries.

* `📁support/` — Modular C source files
* `📁others/` — Contains academic documentation, project reports, presentations, and demo videos.

## 🛠️ How to Compile and Run

### Prerequisites

* A C compiler supporting C99 or later (GCC / MinGW-w64 recommended) or an IDE like Code::Blocks.
* Windows Operating System (required for `system("cls")` console commands).

### Execution Instructions

1. Clone the repository to your local machine:
```bash
git clone https://github.com/aadilazaheen/Personal-Diary-Management-system-CSE115.git
```
2. Navigate into the project root directory:
```bash
cd Personal-Diary-Management-system-CSE115
```
3. Compile the source code using GCC:
```bash
gcc main.c -o diary.exe
```
4. Launch the application executable:
```bash
diary.exe
```