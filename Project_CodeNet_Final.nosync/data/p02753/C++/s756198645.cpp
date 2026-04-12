#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i < n+1 ;i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    if(s[0] == s[1] and s[2] == s[1]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;

}