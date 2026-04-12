#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int r, g, b; cin >> r >> g >> b;
    int tmp = 100*r + 10*g + b;
    if(tmp % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}