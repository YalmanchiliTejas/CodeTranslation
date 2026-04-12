#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>

#define LL long long
#define INF (1<<30)
#define LINF (1000000000000000)
#define PP std::pair<int,int>

int X, Y, Z;
int main() {
	std::cin >> X >> Y >> Z;
	X -= Z;
	std::cout << X / (Y + Z) << std::endl;
	return 0;
}