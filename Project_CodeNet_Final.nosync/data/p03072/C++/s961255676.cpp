#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}
	
	int answer = 1;
	int baseH = H[0];
	
	for (int i = 1; i < N; i++)
	{
		if (baseH <= H[i])
		{
			baseH = H[i];
			answer++;
		}
	}
	
	cout << answer << endl;
	
	return 0;
}