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
    }

    int maxNo = a[num - 1];
    colorList.push_back(a[num - 1]);
    for(int i = num - 2; i >= 0; --i)
    {
        if(maxNo <= a[i])
        {
            colorList.push_back(a[i]);
            maxNo = a[i];
        }
        else
        {
            
            for(int j = 0; j < colorList.size(); ++j)
            {
                if(colorList[j] > a[i])
                {
                    colorList[j] = a[i];
                    break;
                }
            }
            maxNo = colorList[colorList.size() - 1];
        }
    }

    cout << colorList.size() << endl;
	return 0;
}