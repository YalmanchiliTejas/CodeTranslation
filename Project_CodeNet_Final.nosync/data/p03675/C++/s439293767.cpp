#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);

    list<int> l;
    for(i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if(i % 2 == 0)
            l.push_back(a);
        else
            l.push_front(a);
    }

    if(n % 2 == 1)
        l.reverse();

    for(int a : l)
        printf("%d ", a);
    puts("");
    return 0;
}