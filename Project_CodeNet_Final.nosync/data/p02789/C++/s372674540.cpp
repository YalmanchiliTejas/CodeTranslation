#include <iostream>
using namespace std;

int main()
{

	int N, M;

	cin >> N >> M;

	string outStr;

	outStr = (N == M) ? "Yes" : "No";
	cout << outStr <<endl;
	return 0;
}