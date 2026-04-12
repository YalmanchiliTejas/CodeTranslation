#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    vin alpha(26,inf);
    rep(i,n){
        string s;cin>>s;
        vin tmp(26);
        rep(j,s.size())tmp[s[j]-'a']++;
        rep(j,26)alpha[j]=min(alpha[j],tmp[j]);
    }
    string ans;
    string ntoa="abcdefghijklmnopqrstuvwxyz";
    rep(i,26)rep(j,alpha[i])ans+=ntoa[i];
    cout<<ans<<endl;
}