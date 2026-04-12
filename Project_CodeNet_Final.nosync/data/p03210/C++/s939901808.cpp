#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
	int x;
	cin >> x;

	bool ans = false;
	if (x == 5 || x == 3 || x == 7)
		ans = true;

	std::cout << (ans ? "YES" : "NO") << std::endl;
}