/**
*    author:  Dooloper
*    created: 17.09.2020 22:31:35
**/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <functional>
#include <cassert>


using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define PI 3.14159265358979323846264338327950L
const int mod = 1e9 + 7;

int main() {
    cin.tie(0);
    int N;
    ll sum = 0;
    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++){
      cin >> A[i];
      sum += A[i];
      sum %= mod;
    }

    ll ans = 0;
    for (int i : A){
      sum -= i;
      if(sum < 0)
        sum += mod;
      ans += i * sum;
      ans %= mod;
    }

    cout << ans << endl;

    return 0;
}
