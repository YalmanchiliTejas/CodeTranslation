#include<iostream>
#include<cstdio>
#include<functional>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e2+7;
const int inf = 1e5;
const int modn = 1e9+7;
const ld eps = 1e-8;
const long double PI = acos(-1.0);
void qRead(ll &x){x = 0;char a;for(a = getchar();a <'0' || a > '9';a = getchar());for(;a >= '0' && a <= '9';a = getchar())x = x*10 + a-'0';}
void qRead(int &x){x = 0;char a;for(a = getchar();a <'0' || a > '9';a = getchar());for(;a >= '0' && a <= '9';a = getchar())x = x*10 + a-'0';}
ll qpow(ll a,ll b,ll mo = modn){
//    printf("%lld\n",mo);
    ll res = 1;
    while(b){
        if(b & 1)res = (res*a) % mo;
        a = (a*a) % mo;
        b >>= 1;
    }
    return res;
}
ld qpow(ld a,ll b){
    ld res = 1;
    while(b){
        if(b & 1)res *= a;
        a = a*a;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a,ll b){
    if(!b)return a;
    return gcd(b,a%b);
}
//ll vis[maxn],prime[maxn],cnt,smallP[maxn];
//void getPrime(int n){
//    cnt = 0;
//    for(int i = 1;i <= n;i++)vis[i] = 0;
//    for(ll i = 2;i <= n;i++){
//        if(!vis[i]){
//            prime[++cnt] = i;
//            smallP[i] = i;
//        }
//        for(int j = 1;j <= cnt && i*prime[j] <= n;j++){
//            vis[prime[j]*i] = 1;
//            smallP[prime[j]*i] = prime[j];
//            if((i % prime[j]) == 0)break;
//        }
//    }
//}
//ll cnm[maxn][maxn];
//void getCnm(){
//    cnm[0][0] = 1;
//    for(int i = 1;i < maxn;i++){
//        for(int j = 0;j <= i;j++){
//            cnm[i][j] = cnm[i-1][j];
//            if(j)cnm[i][j] += cnm[i-1][j-1];
//            cnm[i][j] %= (modn-1);
//        }
//    }
//}
//ll f[maxn],invF[maxn];
//void getF(){
//    f[0] = invF[0] = 1;
//    for(int i = 1;i < maxn;i++)f[i] = f[i-1]*i % modn;
//    invF[maxn-1] = qpow(f[maxn-1],modn-2);
//    for(int i = maxn-2;i >= 1;i--)invF[i] = invF[i+1]*(i+1) % modn;
//}
char grid[maxn][maxn];
int h,w;
bool judge(int x,int y){
    int check = 0;
    for(int i = 1;i <= w;i++)if(grid[x][i] == '#'){check++;break;}
    for(int i = 1;i <= h;i++)if(grid[i][y] == '#'){check++;break;}
    if(check == 2)return 1;
    return 0;
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i = 1;i <= h;i++)scanf(" %s",grid[i]+1);
    bool nex = 0;
    for(int i = 1;i <= h;i++){
        for(int j = 1;j <= w;j++){
            if(judge(i,j))printf("%c",grid[i][j]),nex = 1;
        }
        if(nex)printf("\n"),nex = 0;
    }
}
