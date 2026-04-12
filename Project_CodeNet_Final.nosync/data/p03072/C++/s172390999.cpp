#include <stdio.h>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple>
#include <climits>
#include <sstream>
using namespace std;

vector<int> h;

int main(int argc, char *argv[])
{
    int res = 0, n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        h.push_back(tmp);

        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (h[j] > h[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            res++;
        }
    }

    cout << res;
    return 0;
}