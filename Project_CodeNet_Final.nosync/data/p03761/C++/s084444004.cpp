#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,n) cin>>s[i];

    map<char,int> mp;
    rep(j,s[0].size()) mp[s[0][j]]++;

    for(int i=0;i<n;i++){
        int m=s[i].size();
        map<char,int> tmp;
        rep(j,m) tmp[s[i][j]]++;
        for(char j='a';j<='z';j++){
            mp[j]=min(mp[j],tmp[j]);
        }
    }
    string ans="";
    for(auto e : mp){
        int m=e.second;
        rep(i,m){
            ans+=e.first;
        }
    }

    cout<<ans<<endl;
}