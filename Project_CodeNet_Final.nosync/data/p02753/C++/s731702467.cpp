#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n;
    std::cout.precision(10);
    int yes=0;
    string s;
    cin>>s;
    j=0;
    k=0;
    for(i=0;i<3;i++)
    {
        if(s[i]=='A')
        {
            j=1;
        }
        else
        {
            k=1;
        }
    }
    if(j&k)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int i,j,k;
    int t;
    std::cout.precision(10);
    t=1;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}