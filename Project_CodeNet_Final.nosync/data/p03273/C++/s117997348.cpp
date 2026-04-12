#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char> cvec;
typedef vector<double> dvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define fs first
#define sc second
int main()	{
  int h,w;
  cin>>h>>w;
  char a[h][w];
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
    }
  }
  vector<bool>ex1(h,false);
  vector<bool>ex2(w,false);
  rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'){
        ex1[i]=true;
        ex2[j]=true;
      }
    }
  }
  rep(i,h){
    if(ex1[i]==true){
      rep(j,w){
        if(ex2[j]==true)
          cout<<a[i][j];
      }
      cout<<endl;
    }
  }
}
  
  