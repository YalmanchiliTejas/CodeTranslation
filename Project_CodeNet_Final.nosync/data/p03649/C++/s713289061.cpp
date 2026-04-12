#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    ll ans = 0;

    while(true){
        bool check = true;
        for(int i = 0; i < N; i++){
            if(a[i] >= N) check = false;
        }

        if(check) break;

        ///////////////////////////////////
        ll s = 0;
        for(int i = 0; i < N; i++) s += a[i] / N;

        ans += s;

        for(int i = 0; i < N; i++){
            ll x = a[i] / N;
            a[i] -= x * N;
            a[i] += s - x;
        }
    }

    cout << ans << endl;
    return 0;
}
