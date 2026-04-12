#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#pragma region DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#pragma endregion DEBUG
#define MOD 1000000007
#define MAX 500005
#define endl "\n"
lli arr[MAX];
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli t;
    t =1 ;
    while(t--){
        int n;
        cin>>n;
        lli s1 = 0;
        lli s2 = 0;
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        for(int i = 0; i<n; i++){
            s1 += arr[i]*arr[i];
            s1 %= MOD;
            s2 += arr[i];
            s2 %= MOD;
        }
        s2 *=s2;
        s2 %= MOD;
       // cout<<s2<<" "<<s1<<endl;
        lli fin = (s2-s1)*binpow(2,MOD-2,MOD);
       fin %= MOD;
        fin += MOD;
        fin %= MOD;
        cout<<fin<<endl;
        

    
    }
}