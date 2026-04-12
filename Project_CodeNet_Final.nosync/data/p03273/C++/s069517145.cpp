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
  vector<string>s(h);
  rep(i,h) cin>>s[i];
  vector<bool>l(h,false),r(w,false);
  rep(i,h)rep(j,w){
    if(s[i][j]=='#'){
      l[i]=true;
      r[j]=true;
    }
  }
  rep(i,h){
    if(l[i]){
      rep(j,w){
        if(r[j])
          cout<<s[i][j];
      }
      cout<<endl;
    }
  }
}