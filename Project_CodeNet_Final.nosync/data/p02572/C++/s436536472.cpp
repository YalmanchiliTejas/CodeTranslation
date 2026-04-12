#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define mod 1000000007
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
void make_unique(vector<ll> vec)
{
sort(all(vec));
vec.resize(unique(all(vec)) - vec.begin());
}


int main() 
{   ios;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t1=1;
    //cin>>t;
    while(t1--)
    {ll q,k,h,p,a,b,v,c,n,m,i,j,flag=0,count=0,move=0;
     cin>>n;
     ll A[n],B[n];
     for(i=0;i<n;i++)
      cin>>A[i];
      B[n-1]=A[n-1];
     for(i=n-2;i>=0;i--)
     {
         B[i]=(B[i+1]+A[i])%mod;
     }
      ll sum=0;
    for(i=0;i<n-1;i++)
    {
       ll temp=(A[i]*B[i+1])%mod;
       sum=(sum+temp)%mod;
    }
    cout<<sum<<endl;
     
     
    }
	return 0;
}
