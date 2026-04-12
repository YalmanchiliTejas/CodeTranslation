#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n, k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;

	for (ll i = 0; i < s.size(); i++)
	{
		if(s[i]!=s[k-1]){
			s[i] = '*';
		}
	}

	cout << s << endl;
}