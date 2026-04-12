#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	int n,s,t;
	cin >> n >> s >> t;
	int dist;
	cout << "? " << s << " " << t << endl;
	cout.flush();
	cin >> dist; 
	vector<int> ds(n+1), dt(n+1);
	vector<pair<int, int> > ds_sorted;
	for(int i=1; i<=n; i++){
		if(i==s or i==t) continue;
		cout << "? " << s << " " << i << endl;
		cout.flush();
		cin >> ds[i];
		cout << "? " << i << " " << t << endl;
		cout.flush();
		cin >> dt[i];
		if(ds[i] + dt[i] == dist){
			ds_sorted.emplace_back(ds[i], i);
		}
	}
	sort(ds_sorted.begin(), ds_sorted.end());
	/*
	for(auto p: ds_sorted){
		cout << p.first << " " << p.second << endl;
		cout.flush();
	}
	*/
	vector<int> ans(1, s);
	int curr = s;
	for(auto pii: ds_sorted){
		cout << "? " << curr << " " << pii.second << endl;
		cout.flush();
		int ret;
		cin >> ret;
		if(ret + dt[pii.second] == dist){
			dist -= ret;
			curr = pii.second;
			ans.push_back(pii.second);
		}
	}

	cout << "! ";
	for(int i: ans){
		cout << i << " ";
	}
	cout << t << endl;
	cout.flush();
	
	int ret;
	if(cin >> ret){
		if(ret == -1){
			return -1;
		}
	}
	return 0;
}
