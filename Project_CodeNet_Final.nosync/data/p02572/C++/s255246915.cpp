#define watch5(a,b,c,d,e) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d << " | "<<#e<<": "<<e<<endl;
#define watch4(a,b,c,d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define watch3(a,b,c) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<endl;
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define sharingan cerr << "\n-------------------------------------------\n\n";
#define watch2(a,b) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<< endl;
#define Yup ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(a) cerr <<#a<<": "<<a<<endl;
#define __gcd(a, b) __algo_gcd(a, b)
#define PI 3.14159265358979323846
#define mod 1000000007
#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    int sum = 0;
    int ar[n];
    int br[n];
    for( int i = 0; i < n; i++ ){
        cin >> ar[i];
        br[i] = ar[i];
    }
    for( int i = n-2; i >= 0; i-- ){
        ar[i] += ar[i+1];
        ar[i] %= mod;
    }
    int ans = 0;
    for( int i = 0; i < n-1; i++ ){
        ans = (ans + (br[i]*ar[i+1])%mod)%mod;
    }
    cout << ans;
}