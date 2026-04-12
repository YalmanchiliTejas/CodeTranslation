#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<time.h>
#include<list>
#include<iomanip>
#include<cstring>
#include<queue>
#define h 1000000007
#define lli long long int
#define pb push_back
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
using namespace std;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n, i,  sum=0,prod;
	cin>>n;
	vector<lli>a(n),b(n);
	for(i=0;i<n;i++) 
	{ 
		cin>>a[i];
		sum+=a[i];
		if(i>0)b[i]=sum-a[0];
	} 
	sum=0;
	b[0]=0;
	for(i=0;i<(n-1);i++) 
	{
		prod=(((b[n-1]-b[i])%h)*(a[i]%h))%h; 
		sum=((sum%h)+prod)%h;
	} 
	cout<<sum<<endl;
  return 0;
} 

