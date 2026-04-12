#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> a(51,1);
vector<ll> p(51,1);

ll f(ll n, ll x)
{
    if(n == 0){
        return 1;
    }
    if(x <= 1){
        return 0;
    }else if(x <= 1 + a.at(n-1)){
        return f(n-1,x-1);
    }else if(x == 2 + a.at(n-1)){
        return p.at(n-1) + 1;
    }else if(x <= 2 + 2*a.at(n-1)){
        return p.at(n-1) + 1 + f(n-1,x-2-a.at(n-1));
    }else if(x == 3 + 2*a.at(n-1)){
        return 2*p.at(n-1) + 1;
    }
    return 0;
}

int main()
{
    ll n,x,i;
    cin >> n >> x;

    for(i = 1;i <= n;++i){
        a.at(i) = 2*a.at(i-1) + 3;
        p.at(i) = 2*p.at(i-1) + 1;
    }

    ll ans = f(n,x);

    cout << ans << endl;

    return 0;
}