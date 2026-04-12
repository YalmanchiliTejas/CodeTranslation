#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n); i > 0; i--)
#define all(n) n.begin(), n.end()
#define print(n) cout << n << endl

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2]) print("No");
    else print("Yes");
    return 0;
}