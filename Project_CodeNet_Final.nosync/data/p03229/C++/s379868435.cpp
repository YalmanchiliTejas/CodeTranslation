#include	<bits/stdc++.h>
using namespace std;

int	main() {
	int N;
	cin >>N;
	vector<long> A(N);
	for (int i=0; i<N; i++)
		cin >>A.at(i);
	sort(A.begin(), A.end());
	long S=0;
	for (int i=0; i<N/2; i++)
		S +=(A.at(N-1-i)-A.at(i))*2;
	S +=A.at(N/2-1)-A.at(N-N/2);
	if (1==N%2)
		S +=max(A.at(N/2+1)-A.at(N/2), A.at(N/2)-A.at(N/2-1));
	cout <<S <<endl;
	return 0;
};
