#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int solve(vector<int>v) {
	int N=v.size();
	int amax=0;
	for (int i = 0; i < N; ++i) {
		if(i>amax)return false;
		int t=v[i]/10;
		amax=max(amax,i+t);
	}
	return true;
}

int main() {	
	int N;cin>>N;
	vector<int>v;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		v.push_back(a);
	}
	bool ok=solve(v);
	reverse(v.begin(),v.end());
	ok&=solve(v);
	if(ok)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}