#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int h,w;
    cin>>h>>w;
    char a[h][w];
    int cnt=0;
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
            if(a[i][j]=='#') cnt++;
        }
    }
    if(cnt==h+w-1) cout<<"Possible";
    else cout<<"Impossible";
}