#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int r,g,b; cin >> r >> g >>b;
    int su = r*100+g*10 + b;
    if(su%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}