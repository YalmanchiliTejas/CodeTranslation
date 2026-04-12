#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++){
		int a;
		cin >> a;
		A.at(i)=a;
	}

	vector<int> B(N,-1);
	for(int i=0;i<N;i++){
		int xx=A.at(i);
		auto iter=lower_bound(B.begin(),B.end(),xx);
		int yy=iter-B.begin();
		B.at(yy-1)=xx;
	}

	/*
	for(int i=0;i<N;i++){
		cout << B.at(i) << " ";
	}
	cout << endl;
	*/

	for(int i=N-1;i>=0;i--){
		if(B.at(i)==-1){
			cout << N-i-1 << endl;
			return 0;
		}
	}
	cout << N << endl;

	return 0;
}
