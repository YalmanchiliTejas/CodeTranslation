
// Author by Md. Jashim Uddin_RMSTU

#include<bits/stdc++.h>
using namespace std;
#define     sf(a)           scanf("%d",&a)
#define     sff(a,b)        scanf("%d %d",&a,&b)
#define     sfff(a,b,c)     scanf("%d %d %d",&a,&b, &c)
#define     pb              push_back
#define     ll              long  long int
#define     fast            ios_base :: sync_with_stdio(false);cin.tie(0)
#define     pi              2*acos(0)
#define     sp              fixed<<setprecision
#define     lcm(a,b)        (a*b)/gcd(a,b)
#define     gcd(a,b)        _gcd(a,b)

#define     forn(i,n)       for(int i=1;i<=n;i++)
#define     min3(a,b,c)     min(a,min(b,c)
#define     M             32000

int main()
{
    ll a=0,b=0;
    string s;
    cin>>s;
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='A') a++;
        else if(s[i]=='B') b++;

        i++;
    }
    if(a>0 && b>0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

return 0;

}
