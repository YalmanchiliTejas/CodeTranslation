#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int inf = 1e9;
const ll linf = 1LL << 50;

int main(int argc, char const* argv[])
{
	char c;
	cin >> c;
	if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')cout << "vowel";
	else cout << "consonant";
	cout << endl;
	return 0;
}
