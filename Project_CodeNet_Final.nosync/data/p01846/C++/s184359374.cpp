//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ld,ld>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

vector<string> jfen_to_matrix(string s){
  vector<string> v;
  string tmp;
  s.push_back('/');
  FOR(i,0,s.size()){
    if(s[i] == '/'){
      v.push_back(tmp);
      tmp = "";
    }
    else if(s[i] == 'b') tmp.push_back('b');
    else{
      ll range = s[i] - '0';
      FOR(j,0,range){
        tmp.push_back('.');
      }
    }
  }
  return v;
}

string matrix_to_jfen(vector<string> &v){
  string res;

  FOR(i,0,v.size()){
    ll t = 0;
    FOR(j,0,v[0].size()){
      if(v[i][j] == '.') t++;
      else{
        if(t != 0)res.push_back(t + '0');
        res.push_back('b');
        t = 0;
      }
    }
    if(t != 0) res.push_back(t+'0');
    res.push_back('/');
  }
  res.pop_back();
  return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    while(s != "#"){
      vector<string> v = jfen_to_matrix(s);
      v[a-1][b-1] = '.';
      v[c-1][d-1] = 'b';
      cout<<matrix_to_jfen(v)<<endl;
      cin>>s>>a>>b>>c>>d;
    }



}

