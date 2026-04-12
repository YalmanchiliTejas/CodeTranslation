#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define int long long
#define P pair<long,long>
#define all(a) a.begin(),a.end()
using namespace std;

signed main(){
    int n; cin>>n;
    vector<string> s(n);
    vector<vector<int>> a(n,vector<int>(26,0));
    rep(i,n){
        cin>>s.at(i);
        rep(j,s.at(i).size()){
            a.at(i).at(s.at(i).at(j)-'a')++;
        }
    }
    string ans="";
    rep(i,26){
        int m=INT_MAX;
        rep(j,n){
            m=min(m,a.at(j).at(i));
        }
        rep(j,m){
            char c='a'+i;
            ans+=c;
        }
    }
    cout<<ans<<endl;
}