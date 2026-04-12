#include <iostream>
#include <set>
using namespace std;
int n,parent[100000],mod=1000000007;
set<int> st;
void init(){
	for(int i=0;i<n;i++) parent[i]=i;
	st.clear();
}
int find(int id){
	if(id==parent[id]) return id;
	parent[id]=find(parent[id]);
	return parent[id];
}
void unite(int a, int b){
	if(find(a)==find(b)) return;
	parent[find(a)]=find(b);
	return;
}
int main(){
	while(true){
		int m;
		cin >> n >> m;
		if(!n) break;
		init();
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
			a--;b--;
			unite(a,b);
		}
		for(int i=0;i<n;i++) st.insert(find(i));
		long long ans=1;
		for(int i=0;i<st.size();i++){
			ans*=2;
			ans%=mod;
		}
		if(m!=0){
			ans++;
			ans%=mod;
		}
		cout << ans << endl;
	}
	return 0;
}