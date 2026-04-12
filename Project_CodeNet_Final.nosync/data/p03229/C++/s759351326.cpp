#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    deque<ll> d;
    d.push_back(a[0]);
    int flag = 0;
    int aft = n - 1;
    int bef = 1;
    while(1){
        if(flag == 0){
            ll k = a[aft];
            if(bef != aft){
                ll t = a[aft - 1];
                ll p = d.front();
                ll q = d.back();
                if(abs(k - p) + abs(t - q) > abs(k - q) + abs(t - p)){
                    d.push_front(k);
                    d.push_back(t);
                }else{
                    d.push_back(k);
                    d.push_front(t);
                }
                flag = 1;
                aft -= 2;
                if(aft < bef){
                    break;
                }
            }else{
                ll p = d.front();
                ll q = d.back();
                if(abs(p - k) > abs(q - k)){
                    d.push_front(k);
                }else{
                    d.push_back(k);
                }
                break;
            }
        }else{
            ll k = a[bef];
            if(aft != bef){
                ll t = a[bef + 1];
                ll p = d.front();
                ll q = d.back();
                if(abs(p - k) + abs(q - t) > abs(q - k) + abs(p - t)){
                    d.push_front(k);
                    d.push_back(t);
                }else{
                    d.push_back(k);
                    d.push_front(t);
                }
                flag = 0;
                bef += 2;
                if(aft < bef){
                    break;
                }
            }else{
                ll p = d.front();
                ll q = d.back();
                if(abs(p - k) > abs(q - k)){
                    d.push_front(k);
                }else{
                    d.push_back(k);
                }
                break;
            }
        }
    }

    ll ans = 0;
    ll now = d.front();
    d.pop_front();
    for(int i = 1; i < n; i++){
        ll t = d.front();
        d.pop_front();
        ans += abs(now - t);
        now = t;
    }

    sort(a, a + n, greater<ll>());

    d.push_back(a[0]);
    flag = 0;
    aft = n - 1;
    bef = 1;
    while(1){
        if(flag == 0){
            ll k = a[aft];
            if(bef != aft){
                ll t = a[aft - 1];
                ll p = d.front();
                ll q = d.back();
                if(abs(k - p) + abs(t - q) > abs(k - q) + abs(t - p)){
                    d.push_front(k);
                    d.push_back(t);
                }else{
                    d.push_back(k);
                    d.push_front(t);
                }
                flag = 1;
                aft -= 2;
                if(aft < bef){
                    break;
                }
            }else{
                ll p = d.front();
                ll q = d.back();
                if(abs(p - k) > abs(q - k)){
                    d.push_front(k);
                }else{
                    d.push_back(k);
                }
                break;
            }
        }else{
            ll k = a[bef];
            if(aft != bef){
                ll t = a[bef + 1];
                ll p = d.front();
                ll q = d.back();
                if(abs(p - k) + abs(q - t) > abs(q - k) + abs(p - t)){
                    d.push_front(k);
                    d.push_back(t);
                }else{
                    d.push_back(k);
                    d.push_front(t);
                }
                flag = 0;
                bef += 2;
                if(aft < bef){
                    break;
                }
            }else{
                ll p = d.front();
                ll q = d.back();
                if(abs(p - k) > abs(q - k)){
                    d.push_front(k);
                }else{
                    d.push_back(k);
                }
                break;
            }
        }
    }

    ll ans_2 = 0;
    now = d.front();
    d.pop_front();
    for(int i = 1; i < n; i++){
        ll t = d.front();
        d.pop_front();
        ans_2 += abs(now - t);
        now = t;
    }

    if(ans > ans_2){
        cout << ans << endl;
    }else{
        cout << ans_2 << endl;
    }
}