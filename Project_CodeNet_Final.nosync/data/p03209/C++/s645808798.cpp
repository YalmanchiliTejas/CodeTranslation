#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll patty(int x){
    if(x==0) return 1;
    else return patty(x-1)*2+1;
}

ll burger(int n){
    if(n==0) return 1;
    else return burger(n-1)*2+3;
}

int main(void){
    ll n,x; cin >> n >> x;
    ll ans = 0;
    ll layer = burger(n)/2+1;
    // cout << layer*2-1 << endl;
    while(true){
        // cout << ans << endl;
        if(n==0){
            if(layer <= x){
                ans++;
            }
            break;
        }
        ll add_layer = burger(n-1)/2+1;
        if(layer == x){
            ans += patty(n-1)+1;
            break;
        }
        else if(layer < x){
            layer += add_layer;
            ans += patty(n-1)+1; 
            n--;
        }else{
            layer -= add_layer;
            n--;
        }
    }
    cout << ans << endl;
    return 0;
}