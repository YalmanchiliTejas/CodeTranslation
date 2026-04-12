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
T lcm( T m, T n )
{
    // 引数に0がある場合は0を返す
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;

    return ((m/gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

// sort big to small
// sort(A,A+N, greater<int>());

// v.front() = -BOUND;
// v.back() = BOUND;

// Iterator
// v.begin
// v.end

int main() {
    long long N;
    string S;
    long long alphabet[26]={0};

    cin >> N;

    // S_0だけ先に入力
    cin >> S;
    rep(j,S.length()){
        alphabet[S[j]-'a']++;
    }

    rep(i,N-1){
        long long alphabet2[26]={0};
        cin >> S;
        rep(j,S.length()){
            alphabet2[S[j]-'a']++;
        }
        rep(j,26){
            alphabet[j] = min(alphabet[j],alphabet2[j]);
        }
    }

    for(int i=0; i<26; i++){
        char alpha='a'+i;
        for(int j=0; j<alphabet[i]; j++){
            cout << alpha;
        }
    }

    cout << endl;
    return 0;
}

