#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fr first
#define sc second
typedef long long ll;
const long long llnrm=LLONG_MAX;
const int nrm=INT_MAX;
const int nrn=INT_MIN;
const int nmax=1e5+5;
const int mod=1e9+7;
using namespace std;
int n,ans,i,j,x,y,z;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>x>>y>>z;
    x-=z;
    cout<<x/(y+z)<<endl;
    return 0;
}

