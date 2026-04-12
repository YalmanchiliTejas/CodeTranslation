#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> a(N, 0);

	int cnt, cnt2;
//	bool check = true;

	cin >> a[0];
	vector<int> b{ a[0] };

	for (cnt = 1; cnt < N; cnt++)
	{
		cin >> a[cnt];
		if (a[cnt]<=b[b.size()-1])
		{
			b.push_back(a[cnt]);
		}
		else
		{
			for (cnt2 = 0; cnt2 < b.size(); cnt2++)
			{
				if (a[cnt] > b[cnt2])
				{
					b[cnt2] = a[cnt];
					//				check = false;
					break;
				}
			}
		}
		
//		check = true;
	}

	cout << b.size() << endl;

	return 0;
}
