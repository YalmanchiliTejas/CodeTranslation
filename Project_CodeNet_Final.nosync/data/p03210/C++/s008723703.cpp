#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>

using namespace std;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()



int main()
{
	int x; cin >> x;
	if (x == 3 || x == 5 || x == 7)cout << "YES" << endl;
	else cout << "NO" << endl;
}