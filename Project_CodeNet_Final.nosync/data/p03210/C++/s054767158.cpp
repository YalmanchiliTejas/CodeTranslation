#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

vector<pair<ll, ll>> pF;


void prime_fact(ll n){
// 素因数分解
for(ll i = 2; i * i <= n; i ++){
ll cnt = 0;
while(n % i == 0){
cnt ++;
n /= i;
}
pair<ll, ll> f = {i, cnt};
pF.push_back(f);
}
if(n != 1){
pF.push_back({n, 1});
}
}


int main(){
    int X;
    cin >> X;
    if(X == 7 || X == 5 || X == 3){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
