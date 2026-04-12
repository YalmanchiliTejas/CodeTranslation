#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
const ll inf = 1e10;
int main(){
    int n, k;
    string s;
    cin >> n >> s >> k;
    k--;
    rep(i,n)cout << ((s[i] != s[k])?'*':s[i]);
    cout << endl;
    return 0;
}