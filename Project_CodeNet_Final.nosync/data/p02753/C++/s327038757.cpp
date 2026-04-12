#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
    string s;
    cin >> s;
    if (s[0]==s[1] && s[1]==s[2]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    
    
    
    return 0;
}
