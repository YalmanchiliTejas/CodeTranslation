#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<ll,ll> P;
typedef pair<ll,ll> Pll;
//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
//long*long<0で判定するな
//開区間と閉区間
//アルファベットが何番目かは x=s[i]-'a'
//bfsはmain()内で　rep(i,h)rep(j,w)rep(i,4)でバグ
//切り上げ：(a+(b-1))/b
//32bit以上は 1ull<<j
// map 初期値0 for(auto itr=mp.begin();itr!=mp.end();++itr) itr->fi itr->se で全探索
// for(auto u:mp) u.fi u.se も可能
//n個のgcd,lcmは一つずつみて更新していく
//大きな数を扱うときは素因数分解した形で持っておく
// (l/a[i]) = l*powmod(a[i],MOD-2)%MOD;
//auto itr=lower_bound(ALL(a),key) a[itr-a.begin()]
int main(){
    string n;
    int k;
    cin >> n >> k;
    ll sz=n.size();
    ll ans=0;
    ll res=1;
    if(sz-1>=k){
        rep(i,k){
            res*=(sz-1-i);
        }
        rep(i,k){
            res/=(k-i);
        }
        res*=pow(9,k);
        ans+=res;
    }
    res=0;
    if(sz>=k){
        int x=n[0]-'0';
        if(k==2){
            res+=(x-1)*(sz-1)*9;
            for(int i=1;i<sz;i++){
                if((n[i]-'0')>0){
                    res+=(n[i]-'0');
                    res+=(sz-i-1)*9;
                    break;
                }
            }
        }else if(k==3){
            res+=(x-1)*81*(sz-1)*(sz-2)/2;
            bool ok=0;
            for(int i=1;i<sz;i++){
                if((n[i]-'0')>0){
                    res+=(sz-i-1)*(sz-i-2)*81/2;
                    res+=((n[i]-'0')-1)*(sz-i-1)*9;
                    for(int j=i+1;j<sz;j++){
                        if((n[j]-'0')>0){
                            res+=(n[j]-'0');
                            res+=(sz-j-1)*9;
                            ok=1;
                            break;
                        }
                    }
                    if(ok) break;
                }
            }
        }else{
            res=x;
        }
        ans+=res;
    }
    cout << ans << endl;
    
}
