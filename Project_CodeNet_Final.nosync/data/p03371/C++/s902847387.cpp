#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  int a,b,c,x,y;
  cin >> a>>b>>c>>x>>y;
  int price1 = a*x + b*y;
  int price2 = 0;
  if(x==y){
    price2 = c*(x+y);
  }
  if(price2 == 0) price2 = price1;

  int price3;
  int c_count = abs(x-y);
  price3 += c*min(x,y)*2; 
  if(max(x,y) == x){
    price3 += a*c_count;
  }else{
    price3 += b*c_count;
  }
  int price4 = c*max(x,y)*2;
  //cout << price1 << " " <<  price2 << " " << price3 << " " << price4 << endl;
  cout << min(min(min(price1, price2),price3),price4) << endl;
  return 0;
}
