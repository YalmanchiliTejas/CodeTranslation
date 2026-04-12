#include "bits/stdc++.h"
#include <math.h>
#include <time.h>
using namespace std;
const long long mod = 1000000007;
#define dump(x)                             \
    if (dbg) {                              \
        cout << #x << " = " << (x) << endl; \
    }
bool dbg = false;
long long gcd(long long a, long long b){
   if (a % b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a % b));
   }
}
long long lcm(long long a, long long b){
   return (a / gcd(a, b))* b;
}
//---------------------------------------------------------------------------------------------------
/*ここからいじる*/
//---------------------------------------------------------------------------------------------------

void solve(){
}
int main(){
    int n;
    cin >> n;
    vector<int>hn(n);
    for(int i = 0; i < n; i++){
        cin >> hn.at(i);
    }
    int num = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        num = max(num, hn.at(i));
        if(hn.at(i) >= num){
            cnt++;
        }
    }
    cout << cnt << endl;
    solve();
    return 0;
}

