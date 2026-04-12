#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
const int mod = 1e9 + 7;
int main() {

    string s;
    cin >> s;

    REP(i, 1, s.length()){
        if(s[i-1] == 'A' && s[i] == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }

    
    cout << "No" << endl;
    
    

    return 0;
}
