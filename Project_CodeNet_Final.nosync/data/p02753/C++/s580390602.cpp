#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

// const int maxn = 
// const int mo = 1e9 + 7;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int a = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); ++i)
        if (s[i] == 'A')
            ++a;
    
    if (a == 3 || a == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
	return 0;
}