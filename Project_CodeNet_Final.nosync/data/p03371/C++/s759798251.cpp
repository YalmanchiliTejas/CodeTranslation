#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>

#define rep(i, n) REP(i, 0, n)
#define REP(i, a, n) for(int i = a ; i < (int)n ; i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define eps 1e-14
#define INF 1e9
#define m0(x) memset(x, 0, sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

signed main(){
  int a, b, c, x, y;
  
  cin >> a >> b >> c >> x >> y;
  
  // 普通に買えばいい場合
  if(a * x + b * y <= c * (x + y)){
    cout << a * x + b * y << endl;
  }else{
    int _min = 1e9;
    
    // 2倍分買えばよさそう
    int max_num = 2 * max(x, y);
    int highest_price, highest_num;
    if(x < y){
      highest_price = b;
      highest_num = y;
    }else{
      highest_price = a;
      highest_num = x;
    }    
    
    while(0 <= max_num && max_num / 2 >= min(x, y)){
      _min = min(_min, highest_price * (highest_num - max_num / 2) + max_num * c);
      max_num-=2;
    }
    cout << _min << endl;
  }
}
