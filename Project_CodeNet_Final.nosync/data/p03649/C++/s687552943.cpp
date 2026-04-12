#include <cmath>
#include <vector>
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

ll n;
vector<ll> vs;
vector<ll> buf;

bool ok()
{
    for(auto e: vs)
    {
        if(e >= n)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    vs.resize(n);
    buf.resize(n);
    for(int i = 0;i < n;i++)
    {
        cin >> vs[i];
    }
    ll sum = 0;
    while(!ok())
    {
        fill(buf.begin(), buf.end(), 0);
        ll c = 0;
        for(int i = 0;i < n;i++)
        {
            buf[i] += vs[i] / n;
            c += buf[i];
        }
        for(int i = 0;i < n;i++)
        {
            ll diff = buf[i] * n - (c - buf[i]);
            vs[i] -= diff;
        }
        sum += c;
    }
    cout << sum << endl;
    return 0;
}