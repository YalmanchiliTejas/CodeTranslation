#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
//cout << std::fixed << std::setprecision(15) << y << endl;


#define MOD 1000000007

int main(){
    ll N;
    cin >> N;

    ll A[N + 1];
    ll sum = 0;
    ll sumA[N + 1];
    REP(i, N){
        cin >> A[i];
        sum += A[i];
        sum %= MOD;
    }
    sumA[0] = sum;
    ll ans = 0;
    REP(i, N){
        sumA[i] = sumA[i - 1] - A[i];
        if(sumA[i] < 0){
            sumA[i] += MOD;
        }
        ans += A[i] * sumA[i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
