#include<iostream>
#include<algorithm>
#define mod 998244353

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n>=30) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}
