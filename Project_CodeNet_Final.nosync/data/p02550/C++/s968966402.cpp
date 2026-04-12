#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007 /*998244353*/;
int main(){
    ll n, m, x;
    cin >> n >> x >> m;
    vector<ll> rem;
    rem.push_back(x % m);
    vector<bool> bl(m);
    ll cur;
    ll stt;
    while(true){
        ll num = rem[rem.size() - 1];
        bl[num] = true;
        num = (num * num) % m;
        if(bl[num]){
            cur = num;
            break;
        }
        else{
            rem.push_back(num);
        }
    }
    for (int i = 0; i < rem.size(); i++)
    {
        if(cur == rem[i])
            stt = i;
    }
    if(n <= rem.size()){
        ll total = x;
        for (int i = 1; i < n; i++){
            total += rem[i];
        }
        cout << total << "\n";
    }
    else{
        ll ls = rem.size() - stt;
        ll total = x;
        for (int i = 1; i < rem.size(); i++){
            total += rem[i];
        }
        n -= rem.size();
        ll div = n / ls;
        ll ama = n % ls;
        ll tmp = 0;
        for (int i = stt; i < rem.size(); i++)
            tmp += rem[i];
        total += div * tmp;
        for (int i = 0; i < ama; i++){
            total += rem[stt + i];
        }
        cout << total << "\n";
    }
}