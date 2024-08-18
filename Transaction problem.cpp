#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Account {
    int accountID;
    int currentBalance;
    Account(int id, int balance) : accountID(id), currentBalance(balance) {}
};
int main() {
    int numAccounts;
    cin >> numAccounts;
    vector<Account> accounts;
    for (int i = 0; i < numAccounts; ++i) {
        int id, balance;
        cin >> id >> balance;
        accounts.emplace_back(id, balance);
    }
    int numTransactions;
    cin >> numTransactions;
    for (int i = 0; i < numTransactions; ++i) {
        int senderID, receiverID, transferAmount;
        cin >> senderID >> receiverID >> transferAmount;
        auto sender = find_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
            return acc.accountID == senderID;
        });
        auto receiver = find_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
            return acc.accountID == receiverID;
        });
        if (sender != accounts.end() && receiver != accounts.end()) {
            if (sender->currentBalance >= transferAmount) {
                sender->currentBalance -= transferAmount;
                receiver->currentBalance += transferAmount;
                cout << "Success" << endl;
            } else {
                cout << "Failure" << endl;
            }
        } else {
            cout << "Failure" << endl;
        }
    }
    cout << endl;
    sort(accounts.begin(), accounts.end(), [](const Account& a1, const Account& a2) {
        return a1.currentBalance < a2.currentBalance;
    });
    for (const auto& account : accounts) {
        cout << account.accountID << " " << account.currentBalance << endl;
    }

    return 0;
}
