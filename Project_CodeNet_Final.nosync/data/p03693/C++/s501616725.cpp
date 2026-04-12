#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=3e5+10;
int main()
{
    FASTINOUT;
    int x,y,z;
    cin>>x>>y>>z;
    int m=x*100+y*10+z;
    if (m%4==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
