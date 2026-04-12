/*..........mango is luv..........*/
#include<bits/stdc++.h>
using namespace std;
#define fk(i,start,end) for(ll i=start;i<ll(end);i++)
typedef long long int ll;
string A="YES";
string B="NO";
ll m=1000000007;
int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
     ll n,sum=0;
     cin>>n;
     vector<ll>a(n)  ;
     fk(i,0,n)
     {
        cin>>a[i];
        sum+=a[i];
        sum=sum%m;
     }
     ll s=0;
     fk(i,0,n)
     {
     	sum-=a[i];
     	if(sum<0)
     	{
     		sum+=m;
     	}
     	s+=sum*a[i];
     	s=s%m;
     }
     cout<<s<<endl;
  return 0;

}