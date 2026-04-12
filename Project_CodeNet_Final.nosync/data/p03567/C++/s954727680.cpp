#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,0,n)
#define SORT(V) sort((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;

int main(){
  string S;
  cin>>S;
  bool CAN=false;
  for(int i=0; i<S.size()-1; ++i){
    if(S.at(i)=='A' && S.at(i+1)=='C') CAN=true;
  }
  if(CAN) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}