#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};


int main(int argc, char const *argv[]) {
  int h,w,cnt=0;
  std::cin >> h >> w;
  char a[10][10];
  rep(i,h){
    rep(j,w){
      std::cin >> a[i][j];
      if(a[i][j]=='#') cnt++;
    }
  }
  if(cnt==h+w-1) std::cout << "Possible" << '\n';
  else std::cout << "Impossible" << '\n';

  return 0;
}
