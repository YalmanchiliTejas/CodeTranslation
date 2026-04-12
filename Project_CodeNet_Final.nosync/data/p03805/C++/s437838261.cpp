#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	int n,m;
	cin >> n >> m;
	
	vector<vector<int>> to(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		--a; --b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	
	vector<int> a(n-1);
	rep(i,n-1) a[i] = i+1;
	
	ll res = 0;
	do{
		bool isNG = false;
		auto result = find(to[0].begin(), to[0].end(), a[0]);
		if(result == to[0].end()) isNG = true;
		rep(i,n-2){
			result = find(to[a[i]].begin(), to[a[i]].end(), a[i+1]);
			if(result == to[a[i]].end()){
				isNG = true;
				break;
			}
		}
		
		if(!isNG) res++;
	}while(next_permutation(a.begin(),a.end()));
	
	
	cout << res << endl;
	return 0;
}