#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, k, n) for (int i = k+1; i < int(n); i++)
typedef long long LL;
typedef pair<int, int> PII;

int pizza_value(int a,int b,int c,int a_num,int b_num, int c_num){
    if(a_num < 0)
        a_num = 0;
    if(b_num < 0)
        b_num = 0;    
    return a*a_num + b*b_num + c*c_num;
}

void f(int a,int b,int c,int x,int y) {
  int ans = 5000*2*1e5;
  int big = x > y? x:y;
  int temp;

  for(int i = 0; i <= big; i++){
      //temp = pizza_value(a,b,c,x - i, y - i, 2*i);
      //cout << "A " << x-i << " B " << y - i << " AB " << 2*i << endl;
      ans = min(ans, pizza_value(a,b,c,x - i, y - i, 2*i));
  }

  cout << ans << endl; 
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  f(a,b,c,x,y);
  return 0;
}