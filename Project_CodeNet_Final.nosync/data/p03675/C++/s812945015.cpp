#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <climits>
#include <unordered_set>
#include <sstream>
#include <stack>

using namespace std;

#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    list<ll> r;
    for(int i = 0;i < n;i++)
    {
        if(i % 2 == 0)
        {
            r.push_back(a[i]);
        }
        else
        {
            r.push_front(a[i]);
        }
    }
    if(n % 2 == 0)
    {
        for(auto e: r)
        {
            cout << e << " ";
        }
    }
    else
    {
        for(auto e = r.rbegin();e != r.rend();e++)
        {
            cout << *e << " ";
        }
    }
    cout << endl;
    return 0;
}