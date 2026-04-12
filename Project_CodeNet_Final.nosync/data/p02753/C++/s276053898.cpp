/*input
ABA

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vii;
#define pb push_back
#define print(a) for(auto x:a){cout<<x<<' ';}cout<<endl;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    string s;cin>>s;
    sort(s.begin(), s.end());
    if(s[0]=='A' && s[2]=='B')
        cout<<"Yes\n";
    else
        cout<<"No\n";
    
}

signed main(){
    IOS
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}