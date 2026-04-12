#include <iostream>
#include <vector>
#include <algorithm>

int* E;
int N, M;
int eval(int ind,std::vector<int>& route)
{
	if (route.size() == N)
		return 1;

	int ans = 0;



	for (int i = 0; i < N; i++)
	{
		std::vector<int> route_n = route;

		if (!E[ind*N + i])
			continue;

		std::vector<int>::iterator iter = std::find(route.begin(), route.end(), i);

		if (iter != route.end())
			continue;

		route_n.push_back(i);

		ans += eval(i, route_n);
	}

	return ans;
}

int main()
{


	std::cin >> N >> M;

	E = new int[N*N];

	std::fill(E, E + N*N, 0);

	for (int i = 0; i < M; i++)
	{
		int a, b;

		std::cin >> a >> b;

		E[(a-1)*N + b-1] = E[(b-1)*N + a-1] = 1;
	}

	std::vector<int> route;
	route.push_back(0);

	int ans = eval(0,route);
	
	std::cout << ans << std::endl;

	return 0;
}