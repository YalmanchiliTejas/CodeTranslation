#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> X(N);
	for(int i = 0; i < N; ++i) cin >> X[i];
	vector<int> Y = X;
	sort(ALL(Y));
	for(int i = 0; i < N; ++i) {
		if(X[i] <= Y[N / 2 - 1]) {
			cout << Y[N / 2] << endl;
		} else {
			cout << Y[N / 2 - 1] << endl;
		}
	}
	return 0;
}
