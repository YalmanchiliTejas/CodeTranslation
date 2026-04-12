//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
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


int chartoint(char c){
  if(c == 'T') return '9' - '0' + 1;
  if(c == 'J') return '9' - '0' + 2;
  if(c == 'Q') return '9' - '0' + 3;
  if(c == 'K') return '9' - '0' + 4;
  if(c == 'A') return '9' - '0' + 5;
  return c - '0';
}

ll compare(string a, string b, char joker, char table){
  if(a[1]!=b[1]){
    if(a[1] == joker) return 0;
    if(b[1] == joker) return 1;
    if(a[1] == table) return 0;
  }
  else{
    int ai = chartoint(a[0]);
    int bi = chartoint(b[0]);
//    cout<<"  compare " <<ai<<" "<<bi<<endl;
    if(ai>bi) return 0;
  }
  return 1;
}

ll ns=0;
ll pri=0;
void game(string n, string e, string s, string w, char joker){
  ll win = 0;
  string tmp = n;
  vector<string> v = {n,e,s,w};
  char table = v[pri][1];
//  cout<<" table is "<<table<<endl;
//  cout<<" "<<pri<<endl;
  FOR(i,1,4){
    if(compare(tmp,v[i],joker,table)){
      win = i;
      tmp = v[i];
//      cout<<"  "<<win<<endl;
    }
  }
  if(win%2 == 0){
    ns++;
  }
  pri = win;
//  cout<<" "<<win<<endl;
}

void res(ll ns){
  if(ns<7)cout<<"EW "<<7-ns<<endl;
  else cout<<"NS "<<ns-6<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    char joker;
    cin>>joker;
    while(joker != '#'){
      vector<string> n,e,s,w;
      FOR(i,0,4){
        FOR(j,0,13){
          string in;
          cin>>in;
          if(i == 0)n.push_back(in);
          if(i == 1)e.push_back(in);
          if(i == 2)s.push_back(in);
          if(i == 3)w.push_back(in);
        }
      }
      ns = 0;
      pri = 0;
      FOR(i,0,13){
        game(n[i],e[i],s[i],w[i],joker);
      }

      res(ns);
      cin>>joker;
    }


}

