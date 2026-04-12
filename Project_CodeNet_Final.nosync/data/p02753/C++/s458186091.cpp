#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define r0 return 0;
#define f(k,i,n,j) for(ll k=i;k<=n;k=k+j)
#define cin(a) cin>>a;
#define loop while(t--)
#define vi vector<int>
#define vii vector<long long int>
#define SORT(v) sort(v.begin(),v.end());
#define mod (1e9+7)
#define crap ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
signed main()
{
    crap;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A')
        a++;
        else b++;
    }
    if(a==3 || b==3)
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;
}