#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, q, sum=0;
    cin >> n >> q;
    REP(i,q){
        int c, k;
        cin >> c >> k;
        if(c==0){
            cout << (sum+k-1)%n+1 << endl;
        }
        else {
            sum = (sum+k)%n;
        }
    }
    return 0;
}

