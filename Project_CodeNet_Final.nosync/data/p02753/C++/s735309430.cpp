/**
                 MD.Faysal Hasan
                Comilla Univesity               **/

#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<string>
#include <stdlib.h>
using namespace std;

#define         rep(i,n)       for ( i=0 ; i<n ; ++i )
#define         rep1(i,n)      for ( i=1 ; i<=n ; ++i )
#define         sajo(str)      sort(str.begin(),str.end())
#define         rev(str)       reverse(str.begin(),str.end())
#define         usajo(str)     sort(str.rbegin(),str.rend())
#define         pi             2*acos(0.0)
#define         nel            printf("\n")
#define         longmx         92233720368547758
#define         gcd(a,b)       __gcd(a,b)
#define         lcm(a,b)       (a/gcd(a,b))*b
#define         yes            cout<<"Yes"<<"\n"
#define         no             cout<<"No"<<"\n"
#define         vcl            vector<ll>
#define         pb             push_back
#define         prl            pair< ll , ll >
#define         mkp(x,y)       make_pair(x,y)
#define         ff             first
#define         sc             second
#define         spc            ' '
#define         nn             '\n'
#define         Faysal         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef         long long int  lli;
typedef         long long      ll;

int main(){Faysal

    lli ans,sum,tot,cnt,mx,mn,idx,chk,rem,ret,tmp,mid,lft,rgt,pos;

    lli tc,n,m,a,b,c,d,g,h,l,r,x,y,i,j,k;

    string s;
    cin>>s;
    n=3;
    bool f=false,ff=false;
    rep(i,n)
    {
        if(s[i]==65)
            f=true;
        else
            ff=true;
    }
    if(f && ff)
        yes;
    else
        no;
    return 0;
}
