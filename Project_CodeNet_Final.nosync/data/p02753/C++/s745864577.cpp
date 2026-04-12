#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    // read in integer 
    string s;
    cin >> s;

    for (int i = 1; i < s.length(); i++) 
        if (s[i] != s[0]){
            cout << "Yes" << endl;
            return 0;
        }
    cout << "No" << endl;
    return 0;
}