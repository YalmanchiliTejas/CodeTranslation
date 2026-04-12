#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

#define ll long long
const ll  modu = 1e9 + 7;
using namespace std;

//int gcd(int a, int b) {
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}
//
//bool comp(vector<int> a, vector<int> b)
//{
//	return a[2] < b[2];
//}
//bool isPal(string s)
//{
//	int start = 0; int end = s.size() - 1;
//	while (start < end)
//	{
//		if (s[start] != s[end]) return false;
//		start++;
//		end--;
//	}
//	return true;
//}
////s && l
////bool comp(vector<int> v1, vector<int> v2)
////{
////	return v1[0] < v2[0];
////}
vector<int> findDuplicates(vector<int>& nums) {

}

int main()
{
	int x; cin >> x;
	if (x == 3 || x == 5 || x == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}