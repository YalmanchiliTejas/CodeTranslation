#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
    ll A, B, C, X, Y;
     cin >> A >> B >> C >> X >> Y;

     ll sum = 0;
     ll a=0, b=0, c=0;
     ll hikaku = A+B;
     ll shoki;
     if(X >= Y){
          shoki = Y;
     }
     else{
          shoki = X;
     }
     if(C*2 <= hikaku){
         sum += shoki*C*2;
         a += shoki;
         b += shoki;
     }
     else{
         sum += (A+B)*shoki;
         a += shoki;
         b += shoki;
     }

     if(X>=Y){
         if(C*2 <= A){
             sum += C*2*(X-a);
         }
         else{
             sum += A*(X-a);
         }
     }
     else{
         if(C*2<=B){
             sum += C*2*(Y-b);
         }
         else{
             sum += B*(Y-b);
         }
     }

     cout << sum << endl;

}
