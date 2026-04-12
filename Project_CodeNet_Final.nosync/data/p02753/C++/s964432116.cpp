#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
#define lld double
#define vi vector<ll>
#define pii pair<int,int>
#define piii pair<pii, ll>
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ppb pop_back
#define d0(x) cout<<x<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<x<<" "<<y<<"\n"
#define d3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define d4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl
#define d5(x,y,z,w,s) cout<<x<<" "<<y<<" "<<z<<" "<<w<<" "<<s<<endl
using namespace std;
const ll mod = 1e9+7;


int main()
{
    char c[3];

    cin>>c;

    if(c[0]!=c[1]||c[1]!=c[2]||c[2]!=c[0])
    {
        d1("Yes");
    }
    else
    {
        d1("No");
    }
}
