#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define sort(s) sort(s.begin(),s.end())
#define reverse(s) reverse(s.begin(),s.end())

//最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
//最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    int x,y;
    cin >> x;
    y = 200*(x/15);
    x *= 800;
    cout << x-y << endl; 

    return 0;
}