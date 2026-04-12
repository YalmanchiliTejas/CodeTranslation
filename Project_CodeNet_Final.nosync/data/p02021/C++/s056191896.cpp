#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	int answer=v[0];
	int sum=v[0];
	for (int i = 1; i < N; ++i) {
		sum+=v[i];
		answer=min(answer,sum/(i+1));
	}
	cout<<answer<<endl;
	return 0;
}

