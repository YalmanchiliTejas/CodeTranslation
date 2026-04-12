#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll>ans(26,INF);
    for (int i = 0; i < n; ++i) {
        vector<ll>now(26,0);
        string s;
        cin >>s;
        ll m=s.size();
        for (int j = 0; j < m; ++j) {
            now[s[j]-'a']++;
        }
        for (int j = 0; j < 26; ++j) {
            ans[j]=min(ans[j],now[j]);
        }
    }
    for (int i = 0; i < 26; ++i) {
        if(ans[i]!=INF){
            for (int j = 0; j < ans[i]; ++j) {
                cout <<(char)('a'+i);
            }
        }
    }
    cout <<endl;
    return 0;
}

