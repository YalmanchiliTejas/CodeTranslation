#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    int x;
    cin >> x;
    if (x == 3 || x == 5 || x== 7){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
	return 0;
}