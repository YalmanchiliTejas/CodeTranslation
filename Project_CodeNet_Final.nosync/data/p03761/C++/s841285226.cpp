#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define P pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
int n;
string s[60];
map<char,int>mp;
signed main(){
    for(int i=0;i<26;i++){
        char c='a'+i;
        mp[c]=200;
    }
    cin>>n;
    rep(i,n){
        cin>>s[i];
        int l=s[i].size();
        map<char,int>mp2;
        rep(j,l){
            mp2[s[i][j]]++;
        }
        rep(j,26){
            char c='a'+j;
            mp[c]=min(mp[c],mp2[c]);
        }
    }
    rep(i,26){
        char c='a'+i;
        if(mp[c]!=200){
            rep(j,mp[c])cout<<c;
        }
    }
    cout<<endl;
    return 0;
}
