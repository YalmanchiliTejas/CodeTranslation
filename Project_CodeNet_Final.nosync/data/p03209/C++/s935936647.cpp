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
typedef pair<int,int> P;

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

ll a[60],p[60];
ll f(ll N, ll X){
    if(N==0)
        return (X<=0) ? 0 :1;
    else if(X <= 1+ a[N-1])
        return f(N-1, X-1);
    else
        return p[N-1] + 1 + f(N-1,X-2-a[N-1]);
}
int main(){
    ll N,X;
    cin >> N >> X;
    a[0]=1, p[0]=1;
    for(int i=1; i<=N; i++){
        a[i]=a[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }

    cout << f(N,X) << endl;
    return 0;
}

