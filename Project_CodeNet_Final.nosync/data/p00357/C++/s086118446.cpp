#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(vector<int> A,int N)
{
	int ikeru = 0;
	for (int i = 0; i < N; ++i)
	{
		if(i > ikeru)
		{
			return false;
		}
		if (i + A[i] > ikeru)
		{
			ikeru = i + A[i];
		}
	}
	return true;
}


int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		A[i] = a[i]/10; 
	}

	if (solve(A,N) == false)
	{
		cout << "no\n";
		return 0;
	}

	reverse(A.begin(),A.end());

	if (solve(A,N))
	{
		cout << "yes\n";
	}
	else
	{
		cout << "no\n";
	}

	
	return 0;
}
