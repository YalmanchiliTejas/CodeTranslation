// Template by [thunder_blade]
// IIIT ALLAHABAD
// includes :)

#include <bits/stdc++.h>
#include <ext/rope> 
using namespace __gnu_cxx;
using namespace std;
#define TEST  int test_case; cin>>test_case; while(test_case--)
#define all(v) (v).begin(),(v).end()
#define fi  first
#define se  second
#define pb push_back
#define mp make_pair
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define pf(x) printf("%f\n",x)
#define ps(x) printf("%s\n",x)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sf(x) scanf("%f",&x)
#define ss(x) scanf("%s",x)
#define pis(x) printf("%d ",x)
#define pls(x) printf("%lld ",x)
#define pfs(x) printf("%f ",x)
#define pss(x) printf("%s ",x)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define mod (1000000007LL)
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const int N = 500005;
int A[N];
int vis[N];
int main()
{
	int n;
	si(n);
	int k = n/2 + 2;
	int lo = k-1;
	int hi = k+1;
	for(int i=0;i<n;i++){
		ll tmp;
		cin>>tmp;
		if(!i){
			vis[k]=1;
			A[k] = tmp;
		}
		else{
			if((n-i)%2){
				vis[lo]=1;
				A[lo--] = tmp;
			}
			else{
				vis[hi]=1;
				A[hi++] = tmp;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(vis[i])
			cout<<A[i]<<" ";
	}
}