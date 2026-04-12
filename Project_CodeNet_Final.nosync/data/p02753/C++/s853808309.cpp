#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
#define REP(i,n) for (int i = 1; i<= (n); i++)
using ll = long long;
using namespace std;

int main() {
    string s;
    cin>>s;
    string ans = (s=="AAA" || s=="BBB") ? "No":"Yes";
    cout<<ans<<endl;
    return 0;
}