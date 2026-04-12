#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=100005;
int n,k;
ll ans;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int b=1;b<=n;b++) {
		for(int x=0;1ll*x*b+k<=n;x++) {
			int tk=max(k,1-x*b);
//			cerr<<x<<"*"<<b<<"="<<x*b<<" delta="<<max(0,min(n-x*b-tk+1,b-tk))<<" delta2=";
			ans+=max(0,min(n-x*b-tk+1,b-tk));
//			int cnty=0;
//			for(int y=k;y+x*b<=n&&y<b;y++) {
//				int a=x*b+y;
//				if (a%b==k&&a<=n) cnty++;
//			}
//			cerr<<cnty<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
