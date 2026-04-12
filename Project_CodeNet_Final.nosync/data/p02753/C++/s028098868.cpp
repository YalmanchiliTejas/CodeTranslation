/*
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineerin College
    Date:07/03/2020
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
#define ld long double
#define ff first
#define ss string 
#define se second
#define alt(v) v.begin(),v.end()
#define pb emplace_back
#define mp make_pair
#define tc(t) cin>>t;while(t--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fab(i,a,b) for(ll i=(a);i<(b);i++)
#define fba(i,a,b) for(ll i=(b);i>=(a);i--)
#define arr(i,n) fab(i,0,n)

ll test=0;
void solve()
{

    int i,j,f=0,k,x1,x2,y,q,m,n;
    string s;
    cin>>s;
    int c1=0,c2=0;
    fab(i,0,3){
    if(s[i]=='A')
    c1++;
    else
    c2++;
    
    }
    if(c1==2 && c2==1)
    cout<<"Yes"<<endl;
    else if(c1==1 && c2==2)
     cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    
}














int main()
{
    ll t=1,s;
    if(test)
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}