#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll a[1024];
int main(void) {
    ll n;
    cin >> n;
    ll k = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    while(1) {
        ll cnt = 0;

        for(int i = 1; i <= n; i++) {
            //cout << a[i] << " ";
            if(a[i] >= n) {
                cnt += a[i]/n;

            }
        }
       // cout << endl;
        k += cnt;
        //cout << k<< endl;
        //int o;
        //cin >> o;

        if(cnt > 0) {
            for(int i = 1; i <= n; i++) {
                ll mod = a[i]%n;
                ll p = a[i]/n;
                a[i] = mod + cnt - p;
            }
        }
        else break;
    }
    cout << k;
    return 0;
}
