#include <bits/stdc++.h>
using namespace std;

bool mygreater(int i, int j){
	return i>=j;
}
int main () {
	int N;
	vector<int> ans;
	cin>>N;
	long long A[N];
	for(int i=0; i< N; i++){
		cin>>A[i];
		auto it = lower_bound(ans.begin(), ans.end(), A[i], mygreater);
		if(it != ans.end()){
			*it = A[i];
		}
		else{
			ans.push_back(A[i]);
		}
	}
	cout<<ans.size()<<"\n";

	return 0;
}