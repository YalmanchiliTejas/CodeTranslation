#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
	int N; cin>>N;
	vector<int> A;
	vector<int> X;	
	for (int i = 0; i<N; i++){
		int x; cin>>x;
		A.push_back(x);
		X.push_back(x);
	}

	sort(X.begin(),X.end());
	int l = X[N/2-1];
	int r = X[N/2];

	for (int i = 0; i<N; i++){
		if (A[i]<=l){
			cout<<r<<"\n";
		} else{
			cout<<l<<"\n";
		}
	}
}
	