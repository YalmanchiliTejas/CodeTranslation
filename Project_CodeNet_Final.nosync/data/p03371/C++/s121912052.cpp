#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll a,b,c,x,y,d,n;

int main(){

  cin >> a>> b >> c >> x >> y;
  d = c*2;
  n= INF;

  rep(i,0,x+1){
    ll j = (ll)i;
    n = min(n, a*j+d*(x-j)+b*max(0LL,y-(x-j)));
  }

  swap(a,b);
  swap(x,y);

  rep(i,0,x+1){
    ll j = (ll)i;
    n = min(n, a*j+d*(x-j)+b*max(0LL,y-(x-j)));
  }
  cout << n << endl;

  return 0;
}

