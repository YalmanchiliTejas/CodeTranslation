#include<iostream>
#include<vector>
#include<set>
int main()
{
	std::vector<int>point(100);
	std::set<int>point_set;
	while (true)
	{
		int p, s;
		char comma;
		std::cin >> p >> comma >> s;
		point[p - 1] = s;
		point_set.insert(s);
		if (p == 0 && s == 0)
		{
			break;
		}
	}
	for (int q; std::cin >> q;)
	{
		std::cout << std::distance(point_set.find(point[q - 1]), point_set.end()) << std::endl;
	}
	return 0;
}
