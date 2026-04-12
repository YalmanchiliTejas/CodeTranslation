


#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>

auto& in = std::cin;
auto& out = std::cout;

int32_t N;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	int a;
	in >> a;
	N *= 10; N += a;
	in >> a;
	N *= 10; N += a;
	in >> a;
	N *= 10; N += a;
	out << (N % 4 == 0 ? "YES" : "NO") << endl;

	return 0;
}
#endif
