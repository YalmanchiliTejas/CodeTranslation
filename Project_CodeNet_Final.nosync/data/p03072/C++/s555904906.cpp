#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i = 0; i < N; i++)
	{
		cin >> H.at(i);
	}
	int answer = 0;
	bool can_view;

	for(int i = 0; i < N; i++)
	{
		can_view = true;

		for(int j = 0; j < i; j++)
		{
			if(H.at(i) < H.at(j))
			{
				can_view = false;
				break;
			}
		}

		if(can_view)
		{
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}