#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iostream>
#include <queue>
#include <math.h>
#include <bits/stdc++.h>
#include <queue>
#include <map>

using namespace std;

#define INF (1ll<<60)
#define INFint (1<<30)
#define MOD 1000000007
#define BOUND 27182818284

typedef long long ll;
typedef long long int lli;
typedef pair<ll,ll> P;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

template<class T>
bool umax(T &a, const T &b){
    if (a<b) {
        a=b; return 1;
    }
    return 0;
}

template<class T>
bool umin(T &a, const T &b) {
    if (b<a) {
        a=b; return 1;
    }
    return 0;
}

// gcd
template<typename T>
T gcd(T a, T b){
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

template<typename T>
T lcm( T m, T n ){
    // 引数に0がある場合は0を返す
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;
    return ((m/gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}


int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};
// v.front() = -BOUND;
// v.back() = BOUND;
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }
    // 素数である
    return true;
}

int main() {
    ll N;
    cin >> N;
    vector<int>H(N);

    rep(i,N){
        cin >> H[i];
    }

    int view=1;
    int highest=H[0];

    for(int i=1; i<N; i++){
        if(H[i]>=highest){
            view++;
            highest=H[i];
        }
    }

    cout << view << endl;
    return 0;
}
