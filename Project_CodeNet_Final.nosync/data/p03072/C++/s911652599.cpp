#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> A(N); // MEOMO: vector の定義数のカッコは丸カッコ()
	for (int i=0; i < N; i++) // MEMO: for iが複数あるときは初期化すること i=0
	{
		cin >> A[i];
	}

	int view;
	int cnt = 0;
	for (int i=0; i < N; i++)
	{
		view = 1;
		for (int j=0; j < i; j++)
		{
			if (A[i] >= A[j])
			{
				//ok
			}else{
				view =0;
			}
		}
		if (view){cnt += 1;}
	}
	cout << cnt << endl;
	return 0;
	
}
