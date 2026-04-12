//  Created by conan1024hao in 2019.
//  Copyright © 2019 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao QQ:810396815
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 10e8
#define INF 10e16
#define MOD 1000000007
#define mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};
char dir[4]={'u','l','d','r'};
ll cmp1(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}
//--------------------------------------------------------------------------
int n;
ll max3(ll i, ll j, ll k)
{
    if (i>=j && i>=k)
        return i;
    return max3(j, k, i);

}
ll maxsequence2(vector<ll>a, ll l, ll u)
{
    if (l > u) return 0;
    if (l == u) return a[l];
    ll m = (l + u) / 2;
 
    /*求横跨左右的最大连续子序列左半部分*/
    ll lmax=a[m], lsum=0;
    for (ll i=m; i>=l; i--) {
        lsum += a[i];
        if (lsum > lmax)
            lmax = lsum;
    }
    
    /*求横跨左右的最大连续子序列右半部分*/
    ll rmax=a[m+1], rsum = 0;
    for(ll i=m+1;i<=u;i++){
        rsum+=a[i];
        if(rsum>rmax)
            rmax=rsum;
    }

        return max3(lmax+rmax,maxsequence2(a, l, m),maxsequence2(a, m+1, u));
}
 
ll maxsequence3(vector<ll>a, ll len)
{
    ll maxsum, maxhere;
    maxsum = maxhere = a[0];   //初始化最大和为a【0】
    for (int i=1; i<len; i++) {
        if (maxhere <= 0)
            maxhere = a[i];  //如果前面位置最大连续子序列和小于等于0，则以当前位置i结尾的最大连续子序列和为a[i]
        else
            maxhere += a[i]; //如果前面位置最大连续子序列和大于0，则以当前位置i结尾的最大连续子序列和为它们两者之和
        if (maxhere > maxsum) {
            maxsum = maxhere;  //更新最大连续子序列和
        }
    }
    return maxsum;
}
ll maxsequence4(vector<ll>a, ll len)
{
    ll maxsum, maxhere;
    maxsum = maxhere = a[1];   //初始化最大和为a【0】
    for (int i=2; i<len; i++) {
        if (maxhere <= 0)
            maxhere = a[i];  //如果前面位置最大连续子序列和小于等于0，则以当前位置i结尾的最大连续子序列和为a[i]
        else
            maxhere += a[i]; //如果前面位置最大连续子序列和大于0，则以当前位置i结尾的最大连续子序列和为它们两者之和
        if (maxhere > maxsum) {
            maxsum = maxhere;  //更新最大连续子序列和
        }
    }
    return maxsum;
}
int permutation(int n,int r)
{
    int a=1;
    for(int i=n-r+1;i<=n;i++)
        a*=i;
    return a;
}
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modpow(long long a, long long n) {//a^n(MOD)を求める
    long long res = 1;
    while (n > 0) {
         if (n & 1) res = res * a % MOD;
         a= a * a % MOD;//次の準備
         n >>= 1;
      }
 return res;
}
//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????        memset()!!!!!!!!!!!!       ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    ll n,k;cin>>n>>k;
    ll ans=0;
    COMinit();
    /*if(k==0){
        cout<<COM(n,2)*2+n<<endl;
        return 0;
    }*/
    for(int i=mmax(1,k);i<=n;i++){
        ans+=n-i;
        //if(i-k>i/2)ans+=i-k-i/2;
    }
    //cout<<ans<<endl;
    for(int i=k+1;i<=n;i++){
        ll m=n-i;
        ll mm=m/i;
        ll mmm=m%i;
        ans+=mm*(i-k);
        if(mmm>=k)ans+=mmm-k+1;
    }
    
    cout<<ans<<Endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------





