#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair

/*int P[10010];
void init(int n){//Union-find
    for(int i=0;i<n;++i)P[i]=i;
}
int root(int a) {
    if(P[a]==a)return a;
    return (P[a]=root(P[a]));
}
bool is_same_set(int a,int b){
    return root(a) == root(b);//代表元を求める
}
void unite(int a,int b){
    P[root(a)]=root(b);
}//対set,グラフ？
//セグメント木？？
*/

double dot_product(xy_t a, xy_t b) { return (conj(a)*b).real(); }//内積
double cross_product(xy_t a, xy_t b) { return (conj(a)*b).imag(); }//外積
xy_t projection(xy_t p, xy_t b) { return b*dot_product(p,b)/norm(b); }//投影
//対図形

#define mod 1000000007
/*ll f[2001];
//int n,k とかしておく

ll pw(ll x, ll y){//euclidの互除法より
    ll a= 1;
    while(y){
        if(y&1){//奇数なら
            a = a*x%mod;
        }
        x = x*x%mod;
        y /= 2;
    }
    return a;
}

ll modinv(ll x){//逆元を求める
    return pw(x, mod - 2 );
}

ll comb(int n,int r){
    if(n<r){
        return 0;
    }
    return f[n] * modinv(f[r])%mod*modinv(f[n-r])%mod;
}//対combination//ただしfは用意してね
*/


/*
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
*/

//cerrはコメントアウトしなくても通る

int main(){
    int a,b,ab,x,y;
    cin >> a>>b>>ab>>x>>y;
    int sum;
    sum=a*x+b*y;
    int temp=INF;
    if(a>ab*2||b>ab*2){
        int z=max(x,y);
        temp=z*ab*2;
    }
    while(x>0&&y>0&&a+b>ab*2){
        x--;y--;
        sum=sum-a-b+ab*2;
    }
    cerr<<x<<" "<<y<<endl;
    cout<<min(sum,temp)<<endl;
    return 0;
}