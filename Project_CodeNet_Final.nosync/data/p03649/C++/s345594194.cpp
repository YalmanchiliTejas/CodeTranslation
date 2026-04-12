#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    ll ar[n];
    ll ans = 0;
    for(int i = 0; i < n; ++i) cin >> ar[i];
    while(1){
        bool jud = 1;
        ll inc = 0;
        ll dec[n] = {0};
        for(int i = 0; i < n; ++i){
            if(ar[i] > n - 1){
                ll tim = ar[i] - (n - 1);
                tim = tim / n + (tim % n > 0);
                ar[i] -= n * tim;
                inc += tim;
                dec[i] = tim;
            }
        }
        ans += inc;
        for(int i = 0; i < n; ++i){
            ar[i] += (inc - dec[i]);
            if(ar[i] > n - 1) jud = 0;
        }
        if(jud) break;
    }
    cout << ans << endl;
    return 0;
}