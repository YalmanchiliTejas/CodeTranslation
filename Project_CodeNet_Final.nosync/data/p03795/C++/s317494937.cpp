#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++) 
#define REP2(i, n) for (int i = n - 1; i >= 0; i--)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    int x = n * 800;
    int y = (n / 15) * 200;
    cout << x - y << endl;
}