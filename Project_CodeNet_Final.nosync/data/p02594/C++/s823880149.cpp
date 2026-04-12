#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int ll;
typedef vector<pair<ll,ll> > vpl;
typedef vector<pair<int,int> > vpi;
typedef vector<ll> vec;
typedef map<ll,ll> mp;
ll GCD(ll a,ll b)
{
    if(a == 0)
    {
        return b;
    }
    return GCD(b%a,a);
}
int main()
{
    FastIO;
    int q = 1;
    //cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        if(n >=30)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}


