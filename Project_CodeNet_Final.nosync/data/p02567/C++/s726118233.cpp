#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end

#include <atcoder/segtree>
//python3 ac-library/expander.py sol.cpp

int f(int a,int b){return max(a,b);}
int e(){return -1;}
int tmp;
bool cmp(int v){return v<tmp;}

int main(){
   int n,q; cin>>n>>q;
   vector<int> a(n);
   rep(i,0,n)cin>>a[i];
   atcoder::segtree<int,f,e> seg(a);
   rep(i,0,q){
      int t; cin>>t;
      if(t==1){
         int x,v; cin>>x>>v; x--;
         seg.set(x,v);
      }
      if(t==2){
         int lb,rb; cin>>lb>>rb; lb--;
         cout<<seg.prod(lb,rb)<<endl;
      }
      if(t==3){
         int x; cin>>x>>tmp; x--;
         cout<<seg.max_right<cmp>(x)+1<<endl;
      }
   }
   return 0;
}