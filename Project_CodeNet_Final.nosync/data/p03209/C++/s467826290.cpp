#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// レベルiバーガーが合計何枚のバン・パティで構成されるか
vector<ll> total(55, 0);

// レベルnの下からxまでを食べた場合、何枚のパティを食べるか？
ll calc(int n, ll x){
    if(n == 0){
        return 1;
    }

    if(x == 1){
        return 0;
    }else if(x > 1 && x <= (total[n-1] + 1)){
        return calc(n-1, x-1);
    }else if(x == total[n-1] + 2){
        return calc(n-1, total[n-1]) + 1;
    }else if(x > total[n-1] + 2 &&
             x < total[n]){
        return calc(n-1, total[n-1]) + 1 + 
               calc(n-1, x - 2 - total[n-1]);
    }else{
        return calc(n-1, total[n-1]) * 2 + 1;
    }
}

int main() {
    int n;
    ll x;
    cin >> n >> x;

    total[0] = 1;
    for(int i = 1; i < total.size(); ++i){
        total[i] = total[i-1] * 2 + 3;
    }

    cout << calc(n, x) << endl;

    return 0;
}