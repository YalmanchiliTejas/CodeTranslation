//自称高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
    int ans = 0;
    int tmp;
    int r, g, b;
    cin >> r >> g >> b;
    int hoe = r*100+g*10+b;
    if (hoe % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
//    cout << ans << endl;
}