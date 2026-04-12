#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define int long
using namespace std;
signed main(void){
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) {
        cin >> s[i];
    }
    string al = "abcdefghijklmnopqrstuvwxyz";
    int p=0;
    int min[28];
    REP(i,28) {
        min[i] = 50;
    }
    REP(i, 28) {
        REP(j, n) {
            REP(k, s[j].size()) {
                if(s[j][k] == al[i]) p++;
            }
            min[i] = fmin(min[i], p);
            p = 0;
        }
    }
    REP(i,28) {
        REP(j, min[i]) {
            cout << al[i];
        }
    }
    cout << endl;
    
    
    
}
