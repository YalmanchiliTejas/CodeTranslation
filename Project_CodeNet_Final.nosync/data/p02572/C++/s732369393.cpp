#include<bits/stdc++.h>
using namespace std;
#define       M                        1000000007
#define       ll                       long long
#define	      FIO		               ios_base::sync_with_stdio(false);cin.tie(NULL)
#define       ifor(st,lim)             for(int i=st;i<lim;i++)
#define       jfor(stt,llim)           for(int j=stt;j<llim;j++)
#define       eifor(st,lim)            for(int i=st;i<=lim;i++)
#define       ejfor(stt,llim)          for(int j=stt;j<=llim;j++)
#define       blank		                 cout<<'\n';
int n,k;
void solve()
{	
	int n; cin>>n;
	int a[n];
	ifor(0,n) { cin>>a[i];}

	ll suffixSum = 0;
	ll ans = 0;
	for(int i=n-1;i>=0;i--) {
		ans = (ans + (a[i]%M*suffixSum%M)%M)%M;
		suffixSum += a[i];
		suffixSum%=M;
	}
	cout<<ans;
	
}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
int t=1;
  while(t--){
    solve();
   } 
}

