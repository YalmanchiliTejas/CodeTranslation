#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <queue>
#include <stdio.h>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)
#define INF 1<<29;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<string>> a(h, vector<string>(w));
    rep(i,h)
    {
      string s;
      cin >> s;
      rep(j,w) a[i][j] = s.substr(j,1);
    }

    bool all_w_zero[h] = {false};
    bool all_h_zero[w] = {false};

    rep(i,h)
        rep(j,w)
        {
      		if(a[i][j] == "#") break;
            if(j == w-1) all_w_zero[i] = true;
        }

    rep(j,w)
        rep(i,h)
        {
            if(a[i][j] == "#") break;
            if(i == h-1) all_h_zero[j] = true;
        }

    rep(i,h)
    {
        if(all_w_zero[i]) continue;
        rep(j,w)
        {
            if(!all_h_zero[j])
                cout << a[i][j];
        }
      	cout << endl;
    }

    return 0;
}