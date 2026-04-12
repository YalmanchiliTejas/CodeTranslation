#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll INF = (1LL << 60);

ll a, b, c;
int x, y;

int main(){
    cin >> a >> b >> c >> x >> y;

    ll res = INF;

    int n = max(x, y);
    for (int i = 0; i <= n; i++){
        ll cnt_a = 0; 
        ll cnt_b = 0; 
        ll cnt_c = 0;
        if (x - i >= 0) cnt_a = x-i;
        if (y - i >= 0) cnt_b = y-i;
        cnt_c = i*2;
        res = min(res, a*cnt_a + b*cnt_b + c*cnt_c);
    }
    
    cout << res << endl;
}

// 5000 5000 4999 1 100000