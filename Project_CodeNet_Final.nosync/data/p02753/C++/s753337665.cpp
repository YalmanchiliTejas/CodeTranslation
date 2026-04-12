#include "bits/stdc++.h"
#include <math.h>
#include <time.h>
using namespace std;
const long long mod = 1000000007;
#define ll long long
#define P pair<int, int>
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
    int a, b;
    string s;
    cin >> s;
    a = 0;
    b = 0;
    for(int i = 0; i < 3; i++){
        if(s.at(i) == 'A'){
            a++;
        }
        else{
            b++;
        }
    }
    int num = a * b;
    if(num == 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    solve();
    return 0;
}

