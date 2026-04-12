#include <bits/stdc++.h>
#define int long long
#define all(c) (c).begin(),(c).end()
#define pii pair<long long,long long>
#define endl '\n'

using namespace std;

signed main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    bool b=false;
    if(s[0]!=s[1] || s[1]!=s[2]){
        b=true;
    }
    if(b) cout << "Yes";
    else cout << "No";
}