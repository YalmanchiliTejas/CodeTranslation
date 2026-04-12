#include	<bits/stdc++.h>
using namespace std;

int	get_idx(vector<int> &q, int v) {
	int L=0;
	int H=q.size()-1;
	while(true) {
		int M=(H+L)/2;
		if (M==L)
			return H;
		if (v<q.at(M))
			H=M;
		else
			L=M;
	}
}

int	main() {
	int N;
	cin >>N;
	vector<int> A(N, 0);
	for (int i=0; i<N; i++)
		cin >>A.at(i);
	vector<int> q;
	q.push_back(A.back());
	for (int i=N-2; i>=0; i--) {
		if (A.at(i)>=q.back()) {
			q.push_back(A.at(i));
			continue;
		}
		if (A.at(i)<q.at(0)) {
			q.at(0)=A.at(i);
			continue;
		}
		int I=get_idx(q, A.at(i));
		q.at(I)=A.at(i);
	}
	cout <<q.size() <<endl;
	return 0;
}

