//  Created by conan1024hao in 2020.
//  Copyright © 2020 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao Twitter/QQ:810396815
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
typedef long long int LL;
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

//---------------------------------------------------------------------------
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
long long COM(int n, int k){
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

// a/b(mod p)
ll waru(ll a,ll b){
    return a*modpow(b,MOD-2)%MOD;
}
//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????统一类型        memset()!!!!!!!!!!!!       ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    COMinit();
    string n;cin>>n;
    ll k;cin>>k;
    ll ans=0;
    ll l=n.length();
    int yy=1;int zz=yy+1;
    for(int i=0;i<l;i++){
        if(k==1){
            ll tmp=mmax(0,n[i]-'0'-1);
            //ans+=tmp*modpow(9, l-1-i);
            if(i==0){
                ans+=(9*(l-1-i));
                ans+=tmp+1;
            }
        }
        else if(k==2){
            ll tmp=mmax(0,n[i]-'0'-1);
            //ans+=tmp*modpow(9, l-1-i)*modpow(9, l-2-i);
            if(i==0){
                ans+=81*COM((l-1-i),2);
                ans+=tmp*(COM(l-1-i,1)*9);
            }
            else{
                if(i==yy&&n[i]=='0'){
                    yy++;
                    continue;
                }
                if(i==yy){
                    ans+=(COM(l-i-1,1)*9);
                    ans+=tmp+1;
                }
            }
        }
        else if(k==3){
            ll tmp=mmax(0,n[i]-'0'-1);
            
            //ans+=tmp*modpow(9, l-1-i)*modpow(9, l-2-i)*modpow(9,l-3-i);
            if(i==0){
                ans+=81*9*COM((l-1-i),3);
                ans+=tmp*(COM(l-1-i,2)*81);
            }
            else{
                if(i==yy&&n[i]=='0'){
                    yy++;
                    zz++;
                    continue;
                }
                if(i==zz&&n[i]=='0'){
                    zz++;
                    continue;
                }
                if(i==yy){
                    ans+=81*(COM(l-i-1,2));
                    ans+=tmp*(COM(l-i-1,1)*9);
                }
                if(i==zz){
                    ans+=(COM(l-i-1,1)*9);
                    ans+=tmp+1;
                }
            }
        }
    }
    /*if(k==1){
        ans+=n[0]-'0';
    }
    /*else if(k==2&&l<=2){
        string ss="";
        ss+=n[l-2];ss+=n[l-1];
        ll ttmp=stoi(ss);
        ll tttmp=ttmp;
        while(tttmp%10!=0)tttmp--;
        ans+=ttmp-tttmp;
    }
    else if(k==3&&l<=3){
        string ss="";
        ss+=n[l-3];ss+=n[l-2];ss+=n[l-1];
        ll ttmp=stoi(ss);
        ans+=ttmp;
    }*/
    cout<<ans<<endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------






