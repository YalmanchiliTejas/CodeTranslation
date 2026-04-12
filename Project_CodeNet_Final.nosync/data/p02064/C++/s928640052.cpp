#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
vector<pair<int,int>> v[2];
vector<int> ans;
int d[310][310];
int main(){
	int i,n,s,t;
	cin >> n >> s >> t;
	for(i=1;i<=n;i++){
		cout << "? " << s << " " << i << endl;
		int x; cin >> x; v[0].push_back({x,i});
		d[s][i] = x;
		cout << "? " << i << " " << t << endl;
		cin >> x; v[1].push_back({x,i});
		d[i][t] = x;
	}
	sort(v[0].begin(),v[0].end());
	ans.push_back(s);
	for(i=0;i<n;i++){
		pair<int,int> p = v[0][i];
		if(p.second==s) continue;
		cout << "? " << s << " " << p.second << endl;
		int x; cin >> x; d[s][p.second] = x;
		if(d[s][p.second] + d[p.second][t]==d[s][t]){
			ans.push_back(p.second);
			s = p.second;
		}
	}
	cout << "! " ;
	for(int x:ans){
		cout << x << " ";
	}
	cout << endl;
}
		
		
	
	
