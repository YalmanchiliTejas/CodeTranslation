// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

//for loop関係
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define repe(i,a,n) for(int i=(a);i<=(n);++i)
#define rrep(i,n,a) for(int i=(n);n>(a);--i)
#define rrepe(i,n,a) for(int i=(n);n>=(a);--i)

//略記
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define ENDL << "\n"

using ll = long long;
using P = pair<int,int>;
using itn = int;

//定数
const int INF = 1<<30;
const ll MOD = 1000000007;
const long double PI =(acos(-1));

//Degree <-> Radian
double toRad(double d){ double rad; rad=d*PI/180; return rad; }
double toDegree(double rad){ double d; d=rad*180/PI; return d; }
//The least common multiple : lcm
ll lcm(int a,int b){ return a*b/__gcd(a,b); }
//素数判定
bool isPrime(int n){
    int i; 
    if(n<2) return 0;
    else if(n==2) return 1;
    if(n%2==0) return 0;
    for(i=3;i*i<=n;i+=2) if(n%i==0) return 0;
    return 1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    bool flaga=0,flagb=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='A') flaga=1;
        if(s[i]=='B') flagb=1;
    }
    if(flaga && flagb) cout << "Yes" ENDL;
    else cout << "No" ENDL;
    
    return 0;
}