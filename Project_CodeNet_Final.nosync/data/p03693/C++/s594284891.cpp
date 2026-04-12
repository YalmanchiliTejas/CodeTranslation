#pragma GCC optimize "-O3"
#pragma GCC target ("avx")
#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define inf (1ll<<60)
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v),greater<int>())
#define SPEED ios::sync_with_stdio(false);cin.tie(0);cout<<fixed<<setprecision(12)
signed gcd(int a, int b){return b?gcd(b,a%b):a;}
signed lcm(int a, int b){return a*b/gcd(a,b);}
//priority_queue<int, vi, greater<int> > que;//昇順

using namespace std;

const int mod=1e9+7;

signed main(){
    SPEED;
    int r,g,b;
    cin >> r >> g >> b;
    g*=10;
    if((g+b)%4==0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
