#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define repone(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define Rep(j,n) for(int j=0;j<(int)(n);++j)
#define Repo(j,o,n) for(int j=o;j<(int)(n);++j)
#define Repone(j,n) for(int j=1;j<(int)(n);++j)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define int long long
#define pb(a) push_back(a)
#define eraser(v,i) (v).erase(v.begin()+(i))
#define pbpair(a,b) push_back(make_pair(a,b))
#define Little 1
const long long INF = 1LL<<60;
#define pairint pair<int,int>
signed main(){
  int x=0,y=0,z=0,w=0,n=0,m=0,o=0;
  std::cin >> x>>y;
  std::vector<string> v(x);
  rep(i,x)std::cin >> v[i];

  rep(i,x){
    Rep(j,y){
      if(v[i][j]=='#'){
        std::cout << '#';
        m++;
      }else{
        for (int k = 0; k < x; k++) {
          if(v[k][j]=='#')n++;
        }
        if(n==0)continue;
        n=0;
        for (int k = 0; k < y; k++) {
          if(v[i][k]=='#')n++;
        }
        if(n>0){
          std::cout << '.';
          m++;
        }
        n=0;
      }
    }
    if(m>0){
      std::cout << '\n';
      m=0;
    }
  }
}