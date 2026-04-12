#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sc(x) scanf("%lld",&(x));
#define pb push_back
#define fi first
#define se second
#define P pair<int,int>
#define endl '\n'
int _,t,a,b,n,m,k,x;

int A[500005];


signed main()
{
    string s;
   cin>>s;
   int n = s.length();
   for(int i=0;i<n;i++)
   if(s[i]=='A')a++;
   else if(s[i]=='B')b++;
   if(a&&b){
    cout<<"Yes";
   }else cout<<"No";

}
