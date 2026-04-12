#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    string s;
    cin>>s;
    long i,n=s.length();
    for(i=0;i<n-1;++i)
    if(s[i]=='A' && s[i+1]=='C') {cout<<"Yes";return 0;}
    cout<<"No";
    return 0;
}
