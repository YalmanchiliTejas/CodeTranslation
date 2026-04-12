#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pi pair<int,int> 
#define pb push_back
#define INF INT_MAX 
#define mod 1000000007ll
#define fi first
#define se second
#define f(i,p,q) for(int i=p;i<q;i++)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define psi(a) printf(" %d",a)
#define poi(a) printf("%d",a)
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)
#define Nline() printf("\n")
#define sstr(str) scanf("%s",str)
#define pstr(str) printf("%s\n",str)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define vi vector<int>
#define vvi vector<vi>
#define all(v) (v).begin(),(v).end()
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())
#define VI(a,n) vi a(n); rep(i,n)cin>>a[i];
#define sq(n) (n)*(n)
#define iso ios::sync_with_stdio(false); cin.tie(0);cout.tie(NULL);
const int base = 1000000007;
 
int main()
{ //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
  //ll n,t;
 // cin>>t>>n;
  /* ll ar[n];
   f(i,0,n) cin>>ar[i]; */
   int n,x;
   string s;
   cin>>n>>s>>x;
   char xx=s[x-1];
   f(i,0,n)
    if(s[i]!=xx)
     s[i]='*';
    cout<<s; 
}
