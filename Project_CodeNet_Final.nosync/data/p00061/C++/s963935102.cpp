#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define rer(i,l,n) for(int i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	int n,sc;
	vi x;
	map<int,int> data;
	for(int i=0;;i++){
		scanf("%d,%d",&n,&sc);
		if(n==0 && sc==0) break;
		data[n]=sc;
		x.push_back(sc);
	}

	sort(all(x));
	x.erase(unique(all(x)),x.end());
	//reverse(all(x));
	int a;
	while(cin>>a){
		//o(data[a]);
		int ans=lower_bound(all(x),data[a])-x.begin();
		o(x.size()-ans);
	}
}