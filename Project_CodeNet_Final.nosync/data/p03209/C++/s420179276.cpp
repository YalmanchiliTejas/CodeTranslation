#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}

vector<ll> num(51),pa(51);

ll cnt(ll n, ll x){
    if(n == 0) return 1;
    else if(x == 1) return 0;
    else if(1 < x && x <= num[n-1]+1) return cnt(n-1,x-1);
    else if(x == num[n-1]+2) return pa[n-1]+1;
    else if(num[n-1]+2 < x && num[n-1]*2+2) return pa[n-1]+1+cnt(n-1,x-2-num[n-1]);
    else return pa[n-1]*2+1;
}

int main(){
    ll n,x; cin >> n >> x;
    num[0] = 1; pa[0] = 1;
    for(int i = 1; i < 51; i++) num[i] = num[i-1] * 2 + 3;
    for(int i = 1; i < 51; i++) pa[i] = pa[i-1] * 2 + 1;
    cout << cnt(n,x) << endl;
    return 0;
}
