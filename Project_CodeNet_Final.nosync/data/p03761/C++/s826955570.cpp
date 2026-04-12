/*     *******************Bismillahir Rahmanir Rahim************************
                          **************************
                          #    MD. ASFAKUL GHANI   #
                          #       *ProMAGFAT*      #
                          #         CSE-25         #
                          #JAHANGIRNAGAR UNIVERSITY#
                          #    Dhaka,Bangladesh    #
                          &&&&&&&&&&&&&&&&&&&&&&&&&#
*/

#include <bits/stdc++.h>
using namespace std;

#define fasterIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define Im int main(int argc, char *argv[])
#define ll long long
#define sc scanf
#define pf printf
#define rn0 return 0
#define rn return
#define f0(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<=n;i++)
#define f2(i,n) for(ll i=n-1;i>=0;i--)
#define pi 2*acos(0.0)
#define modulo 1000003
#define dd double
#define PI 3.14159265358979
#define pi 2*acos(0.0)
#define p_b push_back
#define ps push

/*
ll for_binarySearch(ll a,ll b,ll aa[],ll x){while(a<=b){ll mid=(a+b)/2;if(aa[mid]==x) return 1;else if(aa[mid] > x) b=mid-1;else a=mid+1;}return -1;}
ll for_gcd(ll a,ll b){if(a==0) return b;else return for_gcd(b%a,a);}
ll for_prime(ll x){for (ll i=2;i*i<=x;i++){if(x%i==0) return 0;}return 1;}
void for_swap(char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
ll for_big_mod(ll b,ll p,ll m){if(p==0) return 1;else if(p%2==0){ll k=for_big_mod(b,p/2,m);return (k*k)%m;}else return ((b%m)*(for_big_mod(b,p-1,m)))%m;}
ll for_josephus(ll n,ll k){if(n==1) return 1;return (for_josephus(n-1,k)+k-1)%n+1;}
ll for_gcdExtended(ll a,ll b,ll *x,ll *y){if(a==0){*x=0;*y=1;return b;}ll x1,y1;ll gcd=for_gcdExtended(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
*/

ll vc[105][105];

Im
{
    //fasterIO;

    ll tc;
    cin>>tc;
    ll i=0;
    while (tc--){
        string s1;
        cin>>s1;
        ll sz=s1.size();
        for (ll j=0; j<sz; j++){
            vc[i][s1[j]-97]++;
        }
        i++;
    }

    ll p=i;
    //for (i=0; i<p; i++) sort(vc[i].begin(),vc[i].end());

    string s1;
    for (i=0; i<26; i++){
      ll mn=1234;
        for (ll j=0; j<p; j++){
            mn=min(mn,vc[j][i]);
        }
       for (ll k=0; k<mn; k++){
          s1+=(i+'a');
       }
    }
    sort(s1.begin(),s1.end());
    cout << s1 << endl;

   // main();

    rn0;
}
