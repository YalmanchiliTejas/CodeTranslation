#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define for1(i,l,r) for(int i=(l);i<(r);i++)
#define for2(i,l,r) for(int i=(l);i>(r);i--)
using namespace std;
int n,pos=-1;
int a[205];
vector<int> ans;
signed main(){
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n-1;i>-1;i--){
		for(int j=0;j<n;j++){
			if(a[j]==i){
				pos=j;
				break;
			}
		}
		if(pos==i) continue;
		for(int j=0;j<pos;j++) ans.push_back(1);
		for(int j=pos;j<i;j++){
			ans.push_back(1);
			ans.push_back(n-1);
		}
		for(int j=i;j<n;j++) ans.push_back(1);
		for(int j=pos;j<i;j++) swap(a[j],a[j+1]);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
	//for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
