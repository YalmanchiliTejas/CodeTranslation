#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int lis(vector<int>&A)
{
	int N = A.size();
	vector<int>L(N);

	L[0] = A[0];
	int len = 1;

	for (int i = 1; i < N; i++)
	{
		if (L[len - 1] <= A[i])
		{
			L[len++] = A[i];
		}
		else
		{
			*upper_bound(L.begin(), L.begin()+len, A[i]) = A[i];
		}
	}

	return len;
}

int main() {
	int N;cin>>N;
	vector<int>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	reverse(A.begin(), A.end());

	cout<<lis(A)<<endl;

	return 0;
}