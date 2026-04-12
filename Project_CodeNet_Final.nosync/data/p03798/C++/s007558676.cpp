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
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    //sheep:0,wolf:1
    bool can;
    vin a(n+1);
    rep(i,4){
        bitset<2> tmp(i);
        a[0]=tmp[0];a[1]=tmp[1];
        can=false;
        rep2(j,1,n){
            if(a[j]==0&&a[j-1]==0&&s[j]=='o')a[j+1]=0;
            else if(a[j]==0&&a[j-1]==0&&s[j]=='x')a[j+1]=1;
            else if(a[j]==0&&a[j-1]==1&&s[j]=='o')a[j+1]=1;
            else if(a[j]==0&&a[j-1]==1&&s[j]=='x')a[j+1]=0;
            else if(a[j]==1&&a[j-1]==0&&s[j]=='o')a[j+1]=1;
            else if(a[j]==1&&a[j-1]==0&&s[j]=='x')a[j+1]=0;
            else if(a[j]==1&&a[j-1]==1&&s[j]=='o')a[j+1]=0;
            else if(a[j]==1&&a[j-1]==1&&s[j]=='x')a[j+1]=1;
        }
        if(a[n]==a[0]){
            if(a[0]==0&&a[n-1]==0&&s[0]=='o'&&a[1]==0)can=true;
            else if(a[0]==0&&a[n-1]==0&&s[0]=='x'&&a[1]==1)can=true;
            else if(a[0]==0&&a[n-1]==1&&s[0]=='o'&&a[1]==1)can=true;
            else if(a[0]==0&&a[n-1]==1&&s[0]=='x'&&a[1]==0)can=true;
            else if(a[0]==1&&a[n-1]==0&&s[0]=='o'&&a[1]==1)can=true;
            else if(a[0]==1&&a[n-1]==0&&s[0]=='x'&&a[1]==0)can=true;
            else if(a[0]==1&&a[n-1]==1&&s[0]=='o'&&a[1]==0)can=true;
            else if(a[0]==1&&a[n-1]==1&&s[0]=='x'&&a[1]==1)can=true;
            if(can)break;
        }
    }
    if(can){
        rep(i,n){
            if(a[i])cout<<'W';
            else cout<<'S';
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
}