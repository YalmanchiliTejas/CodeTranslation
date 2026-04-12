#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(ll i = 1;i <= n;i++){
        if(i > k){
            ans += (n / i) * (i - k);
            ans += max(0LL,n % i - k + 1LL);
        }
    }
    if(k != 0){
        cout << ans << endl;
    }
    else cout << n * n << endl;
} 
