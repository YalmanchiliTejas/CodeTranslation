#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI=3.14159265358979323846;
const int64_t waru = 1000000007;
const in INF=1<<30;
#define vec2(a,y,x) vector<vector<int>> a(y,vector<int>(x))
#define vec1(a,n) vector<int> a(n);rep(i,n)cin>>a[i]

bool belong(vector<int> a,int x){
  for(auto y:a){
  	if(y==x) return true;
  }
  return false;
}

int main(){
  int n,m;cin>>n>>m;
  int dai,nyu;
  vec2(tree,n,0);
  rep(i,m){
    cin>>dai>>nyu;
    dai --;nyu --;
    tree[dai].push_back(nyu);
    tree[nyu].push_back(dai);
  }
  vector<int> x(0);
  rep(i,n) x.push_back(i);
  sort(all(x));
  int cnt =0;
  

  do{
    bool flag =true;
    if(x.at(0)!=0) break;
    rep(i,n-1){
      if(!belong(tree[x[i]],x[i+1])){flag=false;break;}
    }
    if(flag) cnt ++;
  }while(next_permutation(all(x)));
cout<<cnt<<endl;
}
