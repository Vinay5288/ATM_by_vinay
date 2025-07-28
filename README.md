💳 Simple ATM Banking System in C

This is a C program that simulates a basic ATM interface, designed for practice and learning. The user can perform core banking functions such as deposits, withdrawals, balance enquiry, password changes, and transaction history tracking.

📌 Features

🔐 Password Authentication
Secure login using a hidden password prompt (* masking with getch()).

💰 Deposit Money
Allows depositing funds into the user's account.

💸 Withdraw Money
Validates password and ensures sufficient balance before allowing withdrawal.

📊 Balance Enquiry
Displays the current balance of the user.

🧾 Transaction History
Shows last 10 transactions (deposit/withdrawal) and writes them to a text file for records.

🔑 Change PIN
Password (PIN) can be changed securely by verifying the current PIN.


🗃️ File Handling

Transactions are logged into:
C:\vinay\codeblocks\TransactionHistory.txt


⚙️ Technologies Used

Language: C (GCC or any standard C compiler)

Functions: getch(), system("cls"), fopen(), fprintf(), strcmp(), etc.

Structures: Used for managing user info and transaction logs

No external libraries – uses standard C and conio.h


📁 Structure

struct user {
    char name[20];
    char pass[10];
    int bal;
};

struct Transaction {
    char type[20];
    int amount;
};

📝 How It Works

1. User authenticates with their password.


2. Menu options allow the user to:

Deposit money

Withdraw money (after password confirmation)

Check account balance

View the last 10 transactions

Change account PIN



3. Transaction records are displayed and written to a file.




---

🚧 Note

This code uses a hardcoded user account (Vinay with password vk5288).

Path for file output must exist (C:\vinay\codeblocks\). You may need to update the path for portability.

Uses conio.h – supported only on Windows. May not work on Linux/Unix without changes.



---

✅ To Run

1. Use Code::Blocks, Turbo C, or any Windows-based C compiler.


2. Compile and run.


3. Default login:

Username: Vinay
Password: vk5288




---

📌 Future Improvements

Support multiple users

Add account number concept

Include date/time for transactions

Migrate to platform-independent input handling


