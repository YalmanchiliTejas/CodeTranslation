#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;

int main()
{
    cin >> n;
    int x,y;
    x = n * 800;
    y = (n / 15);
    y *= 200;

    cout << x - y << endl;
}