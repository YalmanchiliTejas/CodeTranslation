#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>

#define INF (1ll<<60)
#define MOD 1000000007
#define BOUND 27182818284

typedef long long ll;
typedef long long int lli;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

template<class T>bool umax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool umin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using namespace std;

// gcd
int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}
// gcd array
int findGCD(int arr[], int n){
    int result = arr[0];
    for (int i=1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

// sort big to small
// sort(A,A+N, greater<int>());

// v.front() = -BOUND;
// v.back() = BOUND;

// Iterator
// v.begin
// v.end

int main() {
    long long X,Y,Z;
    cin >> X >> Y >> Z;

    cout << (X-Z)/(Y+Z) << endl;
    return 0;
}

