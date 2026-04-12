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
deque<in> b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in a;
  forn(z,n){
    cin>>a;
    if(z%2==0)
      b.push_back(a);
    else
      b.push_front(a);
  }
  if(n%2==0){
    forn(z,n){
      cout<<b.front()<<" ";
      b.pop_front();
    }
  }
  else{
    forn(z,n){
      cout<<b.back()<<" ";
      b.pop_back();
    }
  }
  cout<<endl;
  return 0;
}
