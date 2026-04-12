#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e7;  
using  p = pair<char,int>;

int main(){
   int a,b,c,x,y;
   cin >> a >> b >> c >> x >> y;
   auto c_2 = a+b;
   ll sum = 0;
   
   for (int i = 1; i <= min(x,y); i++)
   {
      sum +=min(c_2,c*2);
   }
   
   sum += x>y ? min(a,c*2)*(x-y) : min(b,c*2)*(y-x);
   
   cout << sum;
}
  
  