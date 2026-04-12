#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> length, pnum;

ll burger(ll n, ll x){
    ll ret = 0;
    if(n == 0){
        return 1;
    }else{
        x--;
        if(x >= length.at(n-1)){
            ret += pnum.at(n-1);
            x -= length.at(n-1);
            if(x > 0){
                ret++;
                x--;
            }
        }
        if(x > 0){
            ret += burger(n-1, x);
        }
    }
    return ret;
}

int main(void){
    int n;
    ll x;
    cin >> n >> x;
    length.resize(n+1);
    pnum.resize(n+1);
    length.at(0) = 1;
    pnum.at(0) = 1;
    for(int i=1; i<=n; i++){
        length.at(i) = length.at(i-1)*2 + 3;
        pnum.at(i) = pnum.at(i-1)*2 + 1;
    }

    cout << burger(n,x) << endl;
    
    return 0;
}