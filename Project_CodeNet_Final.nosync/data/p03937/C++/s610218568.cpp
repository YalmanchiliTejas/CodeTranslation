#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in h,w;
  cin>>h>>w;
  in cc=0;
  string s;
  forn(i,h){
    cin>>s;
    forn(j,w)
      cc+=(s[j]=='#');
  }
  if(cc==(h+w-1))
    cout<<"Possible"<<endl;
  else
    cout<<"Impossible"<<endl;
  return 0;
}
