#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		int a; cin >> a;
		if(i & 1)v.push_back(a);
		else v.insert(v.begin(), a);
	}
	if(!(n & 1)) reverse(v.begin(), v.end());
	for(int i = 0; i < n; ++i){
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}