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
            // not prime num
            return false;
        }
    }
    // prime num
    return true;
}

struct Town{
    int p, num;
    Town(int in_p, int in_num){
        p=in_p;
        num=in_num;
    }

    bool operator<(const Town &another) const
    {
        return p < another.p;
    };
};

int main() {
    int N;
    ll ans=0LL;
    cin >> N;
    vector<int>A(N);
    rep(i,N){
        cin >> A[i];
    }

    vector<int>p1,p2;
    sort(A.begin(), A.end());

    for(int i=0; i<N; i++){
        p1.push_back(A[N-1-i]);
        p1.push_back(A[i]);
    }

    for(int i=0; i<N; i++){
        p2.push_back(A[i]);
        p2.push_back(A[N-1-i]);
    }

    ll temp=0LL;
    for(int i=0; i<N-2; i++){
        temp+=abs(p1[i]-p1[i+1]);
    }
    ans=temp+abs(p1[N-1]-p1[0]);

    temp=0LL;
    for(int i=0; i<N-2; i++){
        temp+=abs(p2[i]-p2[i+1]);
    }
    ans=max(ans,temp+abs(p2[N-1]-p2[0]));
    cout << ans << endl;
    return 0;
}
