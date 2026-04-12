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
bool visited[8]={false};
bool sides[8][8];
int ans=0;

int dfs(int node, int N){
    bool flag= true;
    visited[node]=true;
    for(int i=0; i<N; i++) {
        if (!visited[i] && sides[node][i] && sides[i][node]){
            sides[node][i] = sides[i][node] = false;
            dfs(i,N);
            sides[node][i] = sides[i][node] = true;
        }
    }
    for(int i=0; i<N;i++){
        if(!visited[i]) flag= false;
    }
    if(flag)
        ans++;
    visited[node]= false;

    return 0;
}
int main() {
    long long N,M;
    cin >> N >> M;

    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        sides[a][b] = sides[b][a] = true;
    }

    dfs(0,(int)N);
    cout << ans << endl;
    return 0;
}

