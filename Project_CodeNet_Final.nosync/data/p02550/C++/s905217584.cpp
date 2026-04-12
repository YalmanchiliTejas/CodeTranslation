/*
    title: E.cpp
    author: Akhil
    date: 2020-09-19
    time: 18:32:13
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    long long n, x, m; cin >> n >> x >> m;
    vector<long long> v;
    v.push_back(x);
    unordered_set<long long> s;
    s.insert(x);
    while (true)
    {
        x = (x * x) % m;
        if (s.count(x)) break;
        else v.push_back(x), s.insert(x);
    }
    int idx = -1; 
    for (int i = 0; i < (int) v.size(); i++) if (v[i] == x) {idx = i; break;}
    long long ans = 0; 
    if (n <= idx)
    {
        ans = accumulate(v.begin(), v.begin() + n, 0LL); 
        cout << ans << endl;
        return 0; 
    }
    ans += accumulate(v.begin(), v.begin() + idx, 0LL); 

    long long count = (n - idx) / (v.size() - idx);
    ans += count * accumulate(v.begin() + idx, v.end(), 0LL);

    long long rem = (n - idx) % (v.size() - idx); 
    ans += accumulate(v.begin() + idx, v.begin() + idx + rem, 0LL); 
    cout << ans << endl;
    return 0;
}