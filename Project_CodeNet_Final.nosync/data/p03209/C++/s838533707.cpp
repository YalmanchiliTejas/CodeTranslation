#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> LvCountAll;
vector<ll> LvCountPutty;
ll result = 0;

void resolve(ll N, ll X){
    if(X <= 0){
        return;
    }
    if(X == LvCountAll[N]){
        result += LvCountPutty[N];
        return;
    }

    if(N == 1){
        if(X <= 1){
            return;
        }
        if(2 <= X && X <= 4){
            result += X -1;
            return;
        }
        result += 3;
        return;
    }
    if(LvCountAll[N-1] +1 >= X){
        resolve(N - 1, X-1);
        return;
    }
    if(LvCountAll[N-1] +2 == X){
        result += LvCountPutty[N-1] + 1;
        return;
    }
    else{
        ll Xnokori = X - (LvCountAll[N -1] + 2);
        result += LvCountPutty[N-1] + 1;
        resolve(N-1, Xnokori);
        return;
    }
}

int main() {
    ll N, X;
    cin >> N >> X;


    ll cAll = 1;
    ll cPutty = 1;
    for (int i = 0; i <= N; ++i) {
        if(i > 0){
            cAll = LvCountAll[i-1] * 2 + 3;
            cPutty = LvCountPutty[i-1] * 2 + 1;
        }
        LvCountAll.push_back(cAll);
        //cout << "cALL[" << i << "] = " << cAll << endl;
        LvCountPutty.push_back(cPutty);
        //cout << "cPutty[" << i << "] = " << cPutty << endl;
    }

    resolve(N, X);
    cout << result << endl;

    return 0;
}