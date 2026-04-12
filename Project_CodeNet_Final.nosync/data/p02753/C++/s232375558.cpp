#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define sort(s) sort(s.begin(),s.end())
#define reverse(s) reverse(s.begin(),s.end())
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)

const ll mod = 1e9+7;

//最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

//素数判定
bool isPrime(ll x){
    ll i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

//桁和
int digsum(ll n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

//桁数
int dignum(ll n) {
    int res = 0;
    while(n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

//文字列中の特定の文字カウント
ll stringcount(string s,char c){
    return count(s.cbegin(),s.cend(),c);
}

//階乗
ll ka(ll i){
    ll res=1;
    while(i>0){
        res=res*i;
        i--;
    }
    return res;
}
 
//ncr
ll ncr(ll x,ll y){
    ll a = x;
    ll b = 1;
    if(y>(x/2)){
        y=x-y;
    }
    for(ll i=1;i<y;i++){
        a*=x-i;
        b*=i+1;
    }
    return a/b;
}

//フィボナッチ数列 -92
ll f(ll x){
    ll dp[x+1];
    dp[0]=0;
    dp[1]=1;
    for(ll i=2;i<=x;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[x];
}



int main(){
    string s;
    cin >> s ;
    if(s[0]==s[1]&&s[2]==s[0]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}