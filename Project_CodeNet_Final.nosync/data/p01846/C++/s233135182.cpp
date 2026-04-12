#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

vector<string> toV(string s){
  string x;
  vector<string> res;
  FOR(i,0,s.size()){
    if(s[i]=='b'){
      x.push_back('b');
    }
    else if(s[i]=='/'){
      res.push_back(x);
      string inst;
      x=inst;
    }
    else{
      ll p = s[i] - '0';
      FOR(i,0,p){
        x.push_back('.');
      }
    }
  }
  res.push_back(x);
  return res;
}

string toS(vector<string> v){
  ll m = v[0].size();
  ll n = v.size();
  string res;
  FOR(i,0,n){
    char x='0';
    FOR(j,0,m){
      if(v[i][j]=='b'){
        if(x!='0')res.push_back(x);
        res.push_back('b');
        x = '0';
      }
      else if(v[i][j]=='.'){
        x++;
      }
    }
    if(x!='0')res.push_back(x);
    x='0';
    if(i!=n-1)res.push_back('/');
  }
  return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    vector<string> v;
    cin>>s;
    while(s!="#"){
      ll a,b,c,d;
      cin>>a>>b>>c>>d;
      v=toV(s);
      v[a-1][b-1]='.';
      v[c-1][d-1]='b';
      s=toS(v);
      cout<<s<<endl;

      cin>>s;
    }
}

