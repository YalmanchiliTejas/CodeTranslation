#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = MOD;
    rep(i, max(x*2,y*2)+1){
        int a_num = (i/2 >= x) ? 0 : x-(i/2);
        int b_num = (i/2 >= y) ? 0 : y-(i/2);

        int total = (a_num*a)+(b_num*b)+(i*c);
        ans = min(total, ans);
    }

    cout << ans << endl;
}

