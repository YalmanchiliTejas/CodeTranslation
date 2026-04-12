#include <bits/stdc++.h>
using namespace std;
const int IINF = INT_MAX;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    while(cin >> n, n){
        int sum=0,ma=0,mi=IINF;
        REP(i,n){
            int a;
            cin >> a;
            sum+=a;
            ma = max(ma, a);
            mi = min(mi, a);
        }
        cout << (sum-ma-mi)/(n-2) << endl;
    }
    return 0;
}

