#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> v, w;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; ++i){
		int t;
		cin >> t;
		a.push_back(t);
	}
	for(int i=0; i<n; ++i){
		if(i % 2 == 0) v.push_back(a[i]);
		else w.push_back(a[i]);
	}
	if(n % 2 == 0){
		for(int i=0; i<w.size(); ++i)
			cout << w[w.size()-i-1] << " ";
		for(int i=0; i<v.size(); ++i)
			cout << v[i] << (i == v.size()-1 ? "\n": " ");
	}else{
		for(int i=0; i<v.size(); ++i)
			cout << v[v.size()-i-1] << (n == 1 ? "\n" : " ");
		for(int i=0; i<w.size(); ++i)
			cout << w[i] << (i == w.size()-1 ? "\n": " ");
	}
}