#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

void printarray(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
}

void printpairaraay(int n, pair<int, int> a[])
{
    int x, y;
    for (int i = 0; i < n; i++)
    {
        x = a[i].first;
        y = a[i].second;
        cout << x << " " << y << "\n";
    }
    cout << endl;
}

void swaprange(int b, int t, int e, int a[])
{
    for (int i = 0; i < e - b; i++)
    {
        swap(a[b + i], a[i + t]);
    }
}

int my_binarysearch(int n, int a[], int x)
{
    int ret = 0;
    if (distance(lower_bound(a, a + n, x), upper_bound(a, a + n, x)) != 0)
        ret = 1;
    return ret;
}

int main()
{
    int n, m, x, r;
	r = 0;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
    	cout << distance( a, lower_bound(a, a + n, x) ) << endl;
    }


    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)
