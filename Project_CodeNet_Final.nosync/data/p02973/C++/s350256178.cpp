#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	multiset<int> M;
	for(int i=0;i<n;i++){
		auto it=M.upper_bound(v[i]*-1);
		if(it!=M.end()){
			M.erase(it);
			M.insert(v[i]*-1);
		}
		else M.insert(v[i]*-1);
	}
	cout<<M.size();
}