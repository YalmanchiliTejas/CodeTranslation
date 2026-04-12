#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define rer(i,l,n) for(int i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pii;

int main(){
	int f=0;
	while(1){
		int n,a,b,c;
		pii d[10];
		string s[10];
		cin>>n;
		if(n==0) break;
		if(f==1) cout<<endl;
		rep(i,0,n){
			cin>>s[i]>>a>>b>>c;
			d[i].fi=3*a+c; d[i].se=n-i;
		}
		sort(d,d+n);
		reverse(d,d+n);
		rep(i,0,n){
			o(s[n-d[i].se]<<","<<d[i].fi);
		}
		f=1;
	}
}