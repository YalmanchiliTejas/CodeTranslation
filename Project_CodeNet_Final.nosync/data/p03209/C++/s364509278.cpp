#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll rec(ll n,ll x){
    if (n == 0){
        return 1;
    }

    ll sou = pow(2,n+1) -3;
    ll pat = pow(2,n) -1;

    if (x == 1){
        return 0;
    }
    else if (x <= sou +1){
        return rec(n-1,x-1);
    }
    else if (x == sou +2){
        return pat +1;
    }
    else if (x <= (2*sou) +2){
        return pat + 1 + rec(n-1,x-sou-2);
    }
    else{
        return 2*pat +1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,x;
    cin >> n >> x;
    cout << rec(n,x) << endl;

}