#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> v){
	int dm = 0;
	for(int i=0; i<(int)v.size(); i++){
		if(i*10 <= dm) dm = max(dm, 10*i + v[i]);
	}
	return 10*(v.size() - 1) <= dm;
}

int main(){
	int n;
	cin >> n;
	vector<int> v, u;
	for(int i=0; i<n; i++){
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	u = v;
	reverse(v.begin(), v.end());
	
	cout << (solve(v)&&solve(u)?"yes":"no") << endl;
	
	return 0;
}
