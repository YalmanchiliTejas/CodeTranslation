#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    if((100*r+10*g+b) % 4 == 0)cout << "YES";
    else cout << "NO";
}  