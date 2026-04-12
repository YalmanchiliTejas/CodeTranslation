#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<string> S(N);
    rep(n,0,N) cin>>S.at(n);

    map<char,int> mp;
    for(auto c:S.at(0)) mp[c]++;

    for(auto s:S){
        map<char,int> _mp;
        for(auto c:s) _mp[c]++;
        for(auto m:mp){
            if(_mp.count(m.first)) mp[m.first]=min(m.second,_mp[m.first]);
            else mp[m.first]=0;
        }
    }

    string ans="";
    for(auto m:mp){
        rep(i,0,m.second) ans.push_back(m.first);
    }

    cout<<ans<<endl;
}