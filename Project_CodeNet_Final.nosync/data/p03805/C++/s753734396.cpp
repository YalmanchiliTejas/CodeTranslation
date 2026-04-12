#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	vector<int> a(m),b(m);
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	vector<int> use(n+1,1);
	vector<int> p;
	p.push_back(1);
	use[1]=0;
	int ans=0;
	int exgo=0;
	while(1){
		if(p.size()==0)break;
//		for(int i=0;i<p.size();i++){
//			cout<<p[i];
//		}
//		cout<<endl;
		int u=p.back();
		int v=0;
		p.pop_back();
		for(int i=0;i<m;i++){
			if(a[i]==u){
				v=b[i];
			}
			if(b[i]==u){
				v=a[i];
			}
			if(exgo>=v)v=0;
			if(use[v]==0)v=0;
			if(v)break;
		}
		if(v){
			exgo=0;
			p.push_back(u);
			p.push_back(v);
			use[v]=0;
			if(p.size()==n){
				ans++;
				p.pop_back();
				exgo=v;
				use[v]=1;
			}
		}else{
			exgo=u;
			use[u]=1;
		}

	}
	cout<<ans<<endl;
	return 0;
}
