#include <iostream>
#ifndef LIB_REPEAT_HPP
#define LIB_REPEAT_HPP
#define repeat(i,n) for (int i = 0; i < (n); ++i)
#define repeat_from(i,m,n) for (int i = (m); i < (n); ++i)
#define repeat_one(i,n) for (int i = 1; i <= (n); ++i)
#define repeat_rev(i,n) for (int i = (n)-1; 0 <= i; --i)
#define foreach(it, cont) for (typeof(cont.begin()) it = cont.begin(); it != cont.end(); ++it)
#endif
#ifndef LIB_TYPEDEF_LL_HPP
#define LIB_TYPEDEF_LL_HPP
typedef long long ll;
typedef unsigned long long ull;
#endif
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int m; cin >> m;
    repeat (dataset,m) {
        ll money; int year; int n; cin >> money >> year >> n;
        ll result = 0;
        repeat (way,n) {
            bool is_compound; double rate; ll charge; cin >> is_compound >> rate >> charge;
            ll balance = money;
            if (is_compound) {
                repeat (y,year) {
                    balance += balance * rate - charge;
                }
            } else {
                ll interest = 0;
                repeat (y,year) {
                    interest += balance * rate;
                    balance -= charge;
                }
                balance += interest;
            }
            result = max(result, balance);
        }
        cout << result << endl;
    }
    return 0;
}