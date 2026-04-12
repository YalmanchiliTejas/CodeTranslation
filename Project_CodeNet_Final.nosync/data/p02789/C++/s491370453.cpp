/**
                 MD.Faysal Hasan
                Comilla Univesity               **/

#include<bits/stdc++.h>
#include<algorithm>
#include<utility>
#include <stdlib.h>
using namespace std;
#define         rep(i,n)       for (int i = 0;i<(int)(n);i++)
#define         rep1(i,n)      for (int i = 1;i<=(int)(n);i++)
#define         sajo(str)      sort(str.begin(),str.end())
#define         rsajo(str)     reverse(str.begin(),str.end())
#define         pi             3.14159265359
#define         neli            printf("\n")
#define         gcd(a,b)       __gcd(a,b)
#define         lcm(a,b)       (a/gcd(a,b))*b
#define         yes            cout<<"Yes"<<"\n"
#define         no             cout<<"No"<<"\n"
#define         pf             printf
#define         sf             scanf
#define         pb             push_back
#define         pbk            pop_back
#define         Faysal         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e5+5;
typedef long long int         lli;
typedef long long             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;

int pos(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i+1;
}

int fact(int n)
{
   if(n==0)
      return(1);

   return(n*fact(n-1));
}

int main()
{
    Faysal;
    ll ans,cnt,mx,sum,n,q,x,y,mn;
    string s,t;

    cin>>x>>y;
    if(x==y)
        yes;
    else
        no;

    return 0;
}
