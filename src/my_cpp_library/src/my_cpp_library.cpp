#include "library_header.h"

// deposit amount in the account
bool SavingsAccount::deposit(const float &amount) {
    balance_ += amount;
    // Amount deposited successfully
    return true;
}

// withdraw the amount from the account
bool SavingsAccount::withdraw(const float &amount) {
    if (amount <= balance_) {
        balance_ -= amount;
        return true;
    } else {
        // Insufficient balance
        return false;
    }
}

// return account name
std::string SavingsAccount::get_name() {
    return account_name_;
}

// return account number
int SavingsAccount::get_account_number() {
    return account_nr_;
}

// return account balance
float SavingsAccount::get_balance() {
    return balance_;
}
