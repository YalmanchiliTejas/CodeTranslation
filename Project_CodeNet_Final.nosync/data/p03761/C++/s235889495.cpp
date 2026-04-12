#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
    ll n;cin >>n;
    string s;
    vector<ll>ans(26,INF);
    for (int i = 0; i < n; ++i) {
        vector<ll>now(26,0);
        cin >>s;
        ll m=s.size();
        for (int j = 0; j < m; ++j) {
            now[s[j] - 'a']++;
            //cout << s[i] - 'a' << endl;
        }
        for (int j = 0; j < 26; ++j) {
                ans[j] = min(ans[j], now[j]);
        }
       // for (int k = 0; k < 26; ++k) {
         //   cout <<char('a'+k)<<" "<<ans[k]<<endl;
        //}
        //cout <<'a'<<" " <<now[0]<<endl;
        //cout <<'b'<<" "<<now[1]<<endl;
    }
    for (int i = 0; i < 26; ++i) {
        if(ans[i]!=INF) {
            for (int j = 0; j < ans[i]; ++j) {
                cout << char('a' + i);
            }
        }
    }
    cout <<endl;
    return 0;
}