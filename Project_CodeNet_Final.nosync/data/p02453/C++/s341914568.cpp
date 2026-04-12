#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> p;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		p.push_back(num);
	}
	
	int oper;
	cin >> oper;
	while (oper--)
	{
		int finda;
		cin >> finda;
		vector<int>::iterator pp = lower_bound(p.begin(), p.end(), finda);
			cout << pp - p.begin() << endl;
	}
}
