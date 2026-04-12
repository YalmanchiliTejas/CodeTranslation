#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define sort(s) sort(s.begin(),s.end())
#define reverse(s) reverse(s.begin(),s.end())

//最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
bool isPrime(ll x){
    ll i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

int strsum(const int n){
    string s = to_string(n);
    int b(0);
    rep(i,s.size()){
        b += s[i]-'0';
    }
    return b;
}

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char t = s[k-1];

    rep(i,n){
        if(s[i]!=t) cout << "*";
        else    cout << t;
    }
    cout  << endl;
    return 0;
}