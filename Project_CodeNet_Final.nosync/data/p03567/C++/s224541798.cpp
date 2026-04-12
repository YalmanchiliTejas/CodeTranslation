#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000009
typedef long long ll;

using namespace std;
char a[1000];
int main()
{
    cin >> a;
    int len = strlen(a);
    for(int i = 0; i <len; i++)
    {
        if(a[i] == 'A' && a[i+1] == 'C')
        {
            cout << "Yes" << endl;
            break;
        }
        if(i == len-1)cout << "No" << endl;

    }
    return 0;
}
