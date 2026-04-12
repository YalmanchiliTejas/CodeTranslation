#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	int ANS=0;
	int N;
	int t;
	int max = 0;
	vector<int> H;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		H.push_back(t);
	}

	for (int i =0 ; i < N; i++)
	{
		if (max <= H[i]) {
			max = H[i];
			ANS = ANS + 1;
		}
	}
	
	cout << ANS << endl;
}