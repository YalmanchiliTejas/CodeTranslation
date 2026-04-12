#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <cmath>
#include <functional>

typedef long long ll;
using namespace std;

ll m = pow(10, 9) + 7;

int main(){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    ll ans = 0;
    
    for(int i = 0; i < n; i++){
       sum -= a[i];
       ans = (ans + (a[i] * (sum % m)) % m) % m;
    }

    cout << ans << endl;
}