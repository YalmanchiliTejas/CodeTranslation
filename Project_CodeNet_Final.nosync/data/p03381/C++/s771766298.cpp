#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define num(a) a-'0'
#define maxs(a,b) if(b>a)a=b
#define mins(a,b) if(b<a)a=b;
#define debug(x) cout<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<long long int>
#define v vector
#define p pair
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define ln "\n"	
typedef long long int ll;
typedef long double ld;
typedef double d;
using namespace std;
ll modF=1e9+7;
ll INF=1e18;

void solve(){
	int n;
	scanf("%d",&n);
	vi a(n);
	vi c(n);
	for(int i=0;i < n;i++){
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	sort(all(c));
	double med = ((double)(c[n/2 - 1] + c[n/2]))/2;
	for(int i = 0;i < n; i ++){
		if(a[i] < med){
			printf("%d\n",c[n/2]);
		}
		else{
			printf("%d\n",c[n/2-1]);
		}
	}
}

int main(){
	boost_io;
	solve();
	return 0;
}