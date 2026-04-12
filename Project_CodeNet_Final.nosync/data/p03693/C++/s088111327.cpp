#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int r,g,b;
    cin>>r>>g>>b;
    int num=100*r+10*g+b;
    if (num%4==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}