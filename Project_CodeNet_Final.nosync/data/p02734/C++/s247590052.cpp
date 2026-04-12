#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;


class modInt{
    ll value;
    static const ll mod = 998244353;

public:
    modInt(ll x): value{x % mod}{}

    inline modInt& operator+=(modInt x){
        value = (value + x.value) % mod;
        return *this;
    }

    inline modInt& operator-=(modInt x){
        value = (value + mod - x.value) % mod;
        return *this;
    }

    inline modInt& operator*=(modInt x){
        value = (value * x.value) % mod;
        return *this;
    }


    inline modInt operator/=(modInt x){
        *this *= x.inv();
        return *this;
    }

    inline modInt pow(modInt x, int n){
        modInt res = modInt(1LL);
        while(n > 0){
            if(n & 1)   res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    inline modInt inv(){
        modInt res = pow(value, mod-2);
        return res;
    }

    inline ll get(){
        return value;
    }
};

modInt operator+(modInt x, modInt y){
    return x += y;
}

modInt operator-(modInt x, modInt y){
    return x -= y;
}

modInt operator*(modInt x, modInt y){
    return x *= y;
}

modInt operator/(modInt x, modInt y){
    return x /= y;
}

ostream& operator<<(ostream& os, modInt x){
    return os << x.get();
}


class modIntCombinations{
    vector<modInt> factArray;

    void make_fact(ll x){
        for(auto i = factArray.size(); i <= x+1; i++){
            modInt y = factArray[i-1] * i;
            factArray.push_back(y);
        }
    }

public:
    modIntCombinations(){
        factArray.emplace_back(1);
    }

    modInt fact(ll x){
        if(factArray.size() < x+1){
            make_fact(x);
        }
        return factArray[x];
    }

    modInt comb(ll n, ll k){
        if(n < k){
            return modInt{0};
        }
        else{
            return fact(n) / fact(k) / fact(n - k);
        }
    }

    modInt perm(ll n, ll k){
        if(n < k){
            return modInt{0};
        }
        else{
            return fact(n) / fact(k);
        }
    }
};


int main(){
    int n, s;   cin >> n >> s;
    vector<vector<modInt>> dp(n, vector<modInt>(3001, 0));
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        if(a[i] == s){
            dp[i][a[i]] += modInt{(i+1) * (n-i)};
        }
        else {
            dp[i][a[i]] += modInt{i + 1};
        }
        if(i == 0){
            continue;
        }
        for(int j = 1; j < s; j++){
            if(j + a[i] == s){
                dp[i][j+a[i]] += dp[i-1][j] * modInt{n-i};
            }
            else if(j + a[i] < s){
                dp[i][j + a[i]] += dp[i - 1][j];
            }
            dp[i][j] += dp[i-1][j];
        }
    }

    modInt res{0};
    for(int i = 0; i < n; i++){
        res += dp[i][s];
    }

    cout << res << endl;



    return 0;
}
