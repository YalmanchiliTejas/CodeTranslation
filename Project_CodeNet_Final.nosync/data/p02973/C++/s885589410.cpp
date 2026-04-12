#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const int64_t LINF=8931145141919364364,LMOD=998244353;
// const int dy[]={0,-1,0,1,1,-1,-1,1};
// const int dx[]={1,0,-1,0,1,1,-1,-1};

int main() {
	int n; cin>>n;
	int a[n]; rep(i,n) cin>>a[i];
	multiset<int> ss;
	int ans=1; ss.insert(a[0]);
	ss.insert(-INF);
	ss.insert(-INF);
	for(int i=1;i<n;i++){
		auto itr=ss.lower_bound(a[i]);
		itr--;
		// cout<<tmp<<endl;
		if(*itr!=-INF){
			ss.erase(itr);
		}else{
			ans++;
		}
		ss.insert(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}