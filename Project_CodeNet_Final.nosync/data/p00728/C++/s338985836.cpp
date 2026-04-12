#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)

int main()
{
    int n, p;
    while(cin >> n && n)
    {
        vector<int> points;
        int ans = 0;

        REP(n)
        {
            cin >> p;
            points.push_back(p);
        }

        sort(points.begin(), points.end());
        
        for(int i= 1; i < n -1;i++) ans += points[i];

        cout << ans / (n - 2)<< endl;
    }

    return 0;
}