#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define psortfirst(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.first<b.first;});
#define All(x) (x).begin(),(x).end()
using namespace std;
using pii  = pair<int,int>;
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

int main() {
    ll A[4];
    rep(i,3){
        cin >> A[i];
    }
    // sort(A,A+3);
    cout << ((A[1]*10+A[2])%4==0 ? "YES" : "NO" ) << endl;
}
