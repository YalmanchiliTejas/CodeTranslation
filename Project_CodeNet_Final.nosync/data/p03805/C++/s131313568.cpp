#include <iostream>
#include <vector>
#include <algorithm>


bool check(std::vector<int>& v, std::vector<std::vector<int> >& edge, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool flag = false;
		int k = v.at(i);
		for (int j = 0; j < edge.at(k).size(); j++)
		{
			if (v.at(i + 1) == edge.at(k).at(j))
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			return false;
	}
	return true;

}

int main()
{
	int n, m;
	int count = 0;
	std::cin >> n >> m;
	std::vector<std::vector<int> > edge(n);
	std::vector<int> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		a--;
		b--;
		edge.at(a).push_back(b);
		edge.at(b).push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		v.push_back(i);
	}

	do
	{
		if (v.at(0) != 0)
			break;
		if (check(v, edge, n))
			++count;
	}while (std::next_permutation(v.begin(),v.end()));
	std::cout << count << '\n';
	return 0;
}