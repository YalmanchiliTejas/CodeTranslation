#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
using ll = long long;
using P = pair<ll,int>;
using G = vector<vector<int>>;
const long long INF = 1LL << 60;

int main(){
string s,ans;
cin >> s ;
if(s[0] != s[1] || s[1] != s[2] || s[0] != s[2]) ans = "Yes";
else ans = "No";
cout << ans << endl;
}  