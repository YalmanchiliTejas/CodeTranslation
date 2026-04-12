#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define INT(x) int x; scanf("%d",&x)
#define LL(x) ll x; scanf("%lld",&x)
#define INPUT(x) cin >> x
#define REP1(x,n) for(int x = 0; x < n; x++)
#define REP2(x,s,e) for(int x = s; x <= e; x++)
#define RREP1(x,n) for(int x = n-1; x >= 0; x--)
#define RREP2(x,s,e) for(int x = s; x >= e; x--)
#define BR printf("\n")
#define INF_INT 2147483647
#define INF_LL 9223372036854775807

typedef long long ll;

ll llmax(ll a, ll b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main(){
    INT(n);INT(k);
    
    ll N = n;
    ll K = k;
    
    ll counter = 0;
    
    if(K == 0){
        counter = N;
        counter *= counter;
        cout << counter << endl;
        return 0;
    }
    
    REP2(i,1,N){
        ll amari = N%i;//Kを引いた個数だけ保証
        ll syou = N/i;//最低限保証されてる。
        counter += syou*(llmax(i-K, 0)) + llmax(amari-(K-1), 0);
    }
    
    cout << counter << endl;
    return 0;
}
