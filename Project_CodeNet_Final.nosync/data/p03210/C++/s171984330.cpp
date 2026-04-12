#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
//typedef long long int;
//typedef long long ll;
//typedef pair<int, int> P;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;

int main()
{
    int a;
    cin >> a;
    if(a == 3 || a == 5 || a == 7){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}