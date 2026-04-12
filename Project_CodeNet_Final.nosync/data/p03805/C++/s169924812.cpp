#include	<bits/stdc++.h>
using namespace std;

int	DF(vector<vector<int>> &A, int P, int D, vector<bool> &Done) {
	D++;
	if (A.size()==D+1)
		return 1;
	int S=0;
	Done.at(P)=true;
	for (int i=0; i<A.at(P).size(); i++) {
		int PP=A.at(P).at(i);
		if (Done.at(PP))
			continue;
		S += DF(A, PP, D, Done);
	}
	Done.at(P)=false;
	return S;
}

int	main() {
	int M, N;
	cin >>N >>M;
	vector<vector<int>> A(N+1);
	for (int i=0; i<M; i++) {
		int a, b;
		cin >>a >>b;
		A.at(a).push_back(b);
		A.at(b).push_back(a);
	}
	int S=0;
	vector<bool> Done(N+1, false);
	S=DF(A, 1, 0, Done);
	cout <<S <<endl;
	return 0;
};
