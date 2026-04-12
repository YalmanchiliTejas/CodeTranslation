#include<iostream> 
#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std; 
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
		b.at(i) = { a.at(i) };
	}
	int f = 0;

	for (int j = 0; j < 102; j++)
	{


		for (int i = 0; i < n; i++)
		{
			if (a.at(i) < j)
			{
				f = 1;
				cout << j - 1 << endl;
				break;
			}
			if (i == n - 1)
			{
				break;
			}
			else {
				int x = a.at(i) - j;
				a.at(i + 1) += x;
			}

		}
		for (int k = 0; k < n; k++)
		{
			a.at(k) = b.at(k);
		}
		if (f==1)
		{
			break;
		}

	}
}

