#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <sstream>
#include <queue>
#include <bitset>

using namespace std;
using ll = unsigned long long;
using triplet = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main()
{
#ifdef LOCAL_TEST
    freopen("data.txt", "r", stdin);
#endif
    
    char buff[64];
    
    int n;
    scanf("%d\n", &n);
    vector<string> strings;
    strings.reserve(n);
    
    for (int i = 0; i < n; ++i)
    {
        scanf("%s\n", buff);
        strings.push_back(buff);
        sort(strings.back().begin(), strings.back().end());
    }
    
    vi ci(n, 0);
    string result;
    for (int i = 0; i < strings[0].length(); ++i)
    {
        char ch = strings[0][i];
        int mc = 1;
        for (int j = 1; j < (int)strings.size(); ++j)
        {
            int k = ci[j];
            while (k < strings[j].size() && strings[j][k] < ch) k++;
            ci[j] = k;
            if ((k >= strings[j].length()) || strings[j][k] != ch) break;
            mc++;
            ci[j]++;
        }
        if (mc == n) result.append(1, ch);
    }
    
    printf("%s\n", result.c_str());
    
    return 0;
}