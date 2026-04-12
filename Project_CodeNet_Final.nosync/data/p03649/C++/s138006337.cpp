#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif

using namespace std;

#define ll long long int

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    ll i,a[n+1];
    ll maxi = 0,idx;
    ll cur_idx,cur_max,k;
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++)
    {
        if(a[i] > maxi)
        {
            maxi = a[i];
            idx = i;
        }
    }
    ll ans = 0;
    while(maxi > n - 1)
    {
        cur_max = 0;
        cur_idx = -1;
        k = maxi/n;
        ans += k;
        for(i=0;i<n;i++)
        {
            if(i == idx) a[i] -= (k*n);
            else a[i] += k;
            if(a[i] > cur_max)
            {
                cur_max = a[i];
                cur_idx = i;
            }
        }
        maxi = cur_max;
        idx = cur_idx;
    }
    cout << ans << endl;
    return 0;
}