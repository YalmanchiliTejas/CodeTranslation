#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define INF 1e9

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
}

int main()
{
    init();
    int x;
    cin>>x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout << "No" << endl;
}
