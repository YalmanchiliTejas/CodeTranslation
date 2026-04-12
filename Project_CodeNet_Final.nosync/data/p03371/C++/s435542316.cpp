#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()


ll combination(ll n, ll r){
    if(n < r) return 0;
    if(r == 0||r == n) return 1;
    else if(r == 1) return n;
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

bool checkKaibun(string str){
    string checkStr = str;
    reverse(checkStr.begin(), checkStr.end());
    if(str == checkStr) return true;
    else return false;
}

int keta(ll num){
    int digits = 0;
    while(num > 0){
        num /= 10;
        digits++;
    }
    return digits;
}


int main(){
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if(X < Y){
        swap(X, Y);
        swap(A, B);
    }
    //Cは2枚でA,B各二枚になる
    //とりあえず全探索する？
    ll ans = 1000000000000;
    for(ll i = 0; i <= X; i++){
            ll k = X - i;
            ll j = Y - k;
            if(k < 0) k = 0;
            else if(j < 0) j = 0;
            ll tmpA = i + k;
            ll tmpB = j + k;
            ll price = i * A + j * B + k * C * 2;
            if(tmpA >= X && tmpB >= Y){
                if(ans > price)  ans = price;
            }
    }
    cout << ans << endl;
}