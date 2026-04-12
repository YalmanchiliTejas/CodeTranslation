#include<bits/stdc++.h>
#define endl '\n'
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
int ncr(int n, int k){
    int res = 1;
    if ( k > n - k )
        k = n - k;

    for (int i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int fibonacci(int n){
    double phi = (1 + sqrt(5))/(double)2;
    int nth_fib = round(pow(phi,n)/sqrt(5));
    return nth_fib;
}
signed main(){

#ifndef ONLINE_JUDGE
   // freopen("input.txt","r", stdin);
#endif

    fastIO
    int a, b;
    cin >> a >> b;
    cout << (a == b ? "Yes" : "No");

    return 0;
}
