
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
   int a, b, c, x, y;
   cin >> a >> b >> c >> x >> y;

   
   int  sum=0;
   if(a+b<2*c){ //c*2>a+bならABピザを買うメリットが全くない
       sum=a*x+b*y;
   }
   else{
       sum += 2*c*min(x,y); //xとyのうち少ない方を全部ABピザで賄う
       if(x>y){
           sum += (x-y)*min(a,c*2);
       }
       else{
           sum += (y-x)*min(b,c*2);
       }
   }
   cout << sum << endl;

}