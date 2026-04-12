#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        int n, m, k, l;
        cin >> n >> m >> k >> l;
        if(n == 0)
            return 0;

        vector<pair<int, string> > x(n);
        map<string, int> index;
        for(int i=0; i<n; ++i){
            cin >> x[i].second >> x[i].first;
            x[i].first *= -1;
        }
        sort(x.begin(), x.end());
        for(int i=0; i<n; ++i){
            x[i].first *= -1;
            index[x[i].second] = i;
        }

        vector<bool> fav(n, false);
        for(int i=0; i<m; ++i){
            string s;
            cin >> s;
            fav[index[s]] = true;
        }

        if(n == m || n == k){
            cout << min(m, k) << endl;
            continue;
        }

        int a = 0;
        int b = min(m, k);
        while(a < b){
            int c = (a + b + 1) / 2;

            int tmp = k - c;
            int i = -1;
            while(i+1 < n && tmp >= 0){
                ++ i;
                if(!fav[i])
                    -- tmp;
            }

            long long rest = l;
            tmp = c;
            int j = -1;
            while(tmp > 0){
                ++ j;
                if(fav[j]){
                    if(i < n){
                        if(x[j].second < x[i].second)
                            rest -= max(0, x[i].first - x[j].first);
                        else
                            rest -= max(0, x[i].first - x[j].first + 1);
                    }

                    -- tmp;
                }
            }

            if(rest >= 0)
                a = c;
            else
                b = c - 1;
        }

        cout << a << endl;
    }
}