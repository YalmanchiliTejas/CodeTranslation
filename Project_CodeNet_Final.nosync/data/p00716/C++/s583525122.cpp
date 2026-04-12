#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int initialFund, year, n;
        cin >> initialFund >> year >> n;
        long long maxFund = initialFund;
        for (int j = 0; j < n; j++) {
            int interestKind, fee;
            double interestRate;
            cin >> interestKind >> interestRate >> fee;
            long long fund = initialFund;
            if (interestKind == 0) {
                int interest = 0;
                for (int k = 0; k < year; k++) {
                    interest += fund * interestRate;
                    fund -= fee;
                }
                fund += interest;
            } else {
                for (int k = 0; k < year; k++) {
                    fund += fund * interestRate;
                    fund -= fee;
                }
            }
            if (maxFund < fund) {
                maxFund = (long long) fund;
            }
        }
        cout << maxFund << endl;
    }
}