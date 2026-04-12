#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <functional>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

#include <cassert>
using namespace std;

int main(void){

	int N;
	cin >> N;
	vector<int> X(N),Xs(N);
	for(int i=0;i<N;++i){
		cin >> X[i];
	}
	Xs=X;
	sort(Xs.begin(),Xs.end());

	int c1 = Xs[N/2-1];
	int c2 = Xs[N/2];

	for(int i=0;i<N;++i){
		if(X[i]>c1){cout << c1 << endl;}
		else{cout << c2 << endl;}
	}

	return 0;
}