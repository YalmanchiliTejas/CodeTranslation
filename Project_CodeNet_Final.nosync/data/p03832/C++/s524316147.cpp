#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long g = a;
    if(b != 0){
        g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return g;
}

long long mod_inverse(long long a, long long m)
{
    long long x, y;
    extgcd(a, m, x, y);
    return (x % m + m) % m;
}

class FactorialCalculation
{
private:
    const int mod;
    vector<long long> factorial;
    vector<long long> invFactorial;
public:
    FactorialCalculation(int n, int mod) : mod(mod)
    {
        factorial.resize(n+1, 1);
        invFactorial.resize(n+1, 1);
        for(int i=1; i<=n; ++i){
            factorial[i] = factorial[i-1] * i % mod;
            invFactorial[i] = mod_inverse(factorial[i], mod);
        }
    }
    long long getFactorial(int n){
        return factorial[n];
    }
    long long getInvFactorial(int n){
        return invFactorial[n];
    }
    long long getPermutation(int n, int r){
        if(n < r)
            return 0;
        return factorial[n] * invFactorial[n-r] % mod;
    }
    long long getCombination(int n, int r){
        if(n < r)
            return 0;
        return getPermutation(n, r) * invFactorial[r] % mod;
    }
    long long getHomogeneous(int n, int r){
        return getCombination(n+r-1, r);
    }
};

const int MOD = 1000000007;

int main()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    FactorialCalculation fc(n, MOD);

    vector<long long> dp(n+1, 0);
    dp[n] = 1;
    for(int i=a; i<=b; ++i){
        for(int j=1; j<=n; ++j){
            long long tmp = 1;
            int x = 0;
            for(int f=1; f<=d; ++f){
                x += i;
                if(j < x)
                    break;

                tmp *= fc.getCombination(j-x+i, i);
                tmp %= MOD;

                if(f >= c){
                    long long add = dp[j] * tmp;
                    add %= MOD;
                    add *= fc.getInvFactorial(f);
                    add %= MOD;
                    dp[j-x] += add;
                    dp[j-x] %= MOD;
                }
            }
        }
    }
    cout << dp[0] << endl;

    return 0;
}
