#include<iostream>

using namespace std;

int main() {
    int m;
    cin >> m;
    for (; m>0; m--) {
        int init, years, n, cost, fund_max;
        double rate;
        bool is_compound;
        cin >> init >> years >> n;
        fund_max = init;
        for (; n>0; n--) {
            cin >> is_compound >> rate >> cost;
            int fund = init;
            if (is_compound) {
                for (int y=0; y<years; y++) {
                    fund = (int)(fund*rate+fund-cost);
                }
            }
            else {
                int interest = 0;
                for (int y=0; y<years; y++) {
                    interest += (int)(fund*rate);
                    fund = fund-cost;
                }
                fund += interest;
            }
            fund_max = fund_max>fund? fund_max: fund;
        }
        cout << fund_max << endl;
    }
    return 0;
}