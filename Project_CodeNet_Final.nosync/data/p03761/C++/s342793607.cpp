#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int n;cin>>n;
    vector<string> S(n);
    map<char,int> mp;
    REP(i,n){
        map<char,int> cnt;
        cin>>S[i];
        REP(j,S[i].size()) cnt[S[i][j]]++;
        if(i==0) mp=cnt;
        else REP(j,26){
            mp[char(j+'a')]=min(mp[char(j+'a')],cnt[char(j+'a')]);
        }
    }
    string ans;
    for(auto e:mp) ans+=string(e.second,e.first);
    cout<<ans<<endl;
}
