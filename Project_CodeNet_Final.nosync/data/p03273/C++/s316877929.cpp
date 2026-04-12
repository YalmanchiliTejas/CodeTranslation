#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 7+1e18
#define lld long double
#define eps 0.000001
#define endl '\n'
using namespace std ;

int main()
{

    lli h,w;
    cin>>h>>w;
    char a[h][w],ans[h][w];

    loopl(i,0,h)
    loopl(j,0,w) 
    cin>>a[i][j];
    

    loopl(i,0,h)
    loopl(j,0,w) ans[i][j]='0';


    loopl(i,0,h)
    {
    	lli cnt=0;
    	loopl(j,0,w) if(a[i][j]=='.') cnt++;
        if(cnt!=w)
        {
           loopl(j,0,w) ans[i][j]=a[i][j];
        }

    }
   

    loopl(j,0,w)
    {
    	lli cnt=0;
    	loopl(i,0,h) if(ans[i][j]=='.'||ans[i][j]=='0') cnt++;
        if(cnt==h)
        {
           loopl(i,0,h) ans[i][j]='0';
        }

    }

    loopl(i,0,h) 
    {
    	lli cnt=0;
    	loopl(j,0,w)
    	if(ans[i][j]!='0') {cout<<ans[i][j]; cnt++;}
    	if(cnt!=0)cout<<endl;
    }
}