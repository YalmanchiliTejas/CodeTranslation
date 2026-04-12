#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <vector>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define vi vector<int>
#define sort_v(a) sort(a.begin(), a.end())

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int a;

    cin >> a;
    if (a == 7 || a == 3 || a == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
