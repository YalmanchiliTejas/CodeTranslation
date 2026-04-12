#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP_S(i, n, s) for(int i = s; i < (int)(n); i++)
int main()
{
   	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;

    int a[100010];
    vector<int> colorList;
    REP(i, num)   
    {
        cin >> a[i];
        a[i] = -a[i];
        if(i == 0)
        {
            colorList.push_back(a[0]);
            continue;
        }

        if(colorList[colorList.size() - 1] <= a[i])
        {
            colorList.push_back(a[i]);
            continue;
        }        
        *upper_bound(colorList.begin(), colorList.end(), a[i]) = a[i];
    }
    cout << colorList.size() << endl;
	return 0;
}