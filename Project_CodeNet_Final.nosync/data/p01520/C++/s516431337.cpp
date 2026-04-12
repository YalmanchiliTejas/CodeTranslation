#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)
#define all(n) n.begin(),n.end()

const int MAXN = 100, MAXT = 1440 * 2;
int main()
{
    int n, t, e, w[MAXN + 10], check[MAXT + 10] = {};
    memset(check, -1, sizeof(check));
    cin >> n >> t >> e;
    REP(n)
    {
        cin >> w[i];
        for(int j = 1; j * w[i] <= MAXT; j++) check[j * w[i]] = i + 1;
    }
    
    int ans = -1;
    REP(e + 1)
    {
        if(t - i <= 0) continue;
        if(check[t - i] != -1) { ans = check[t - i]; break;}
        if(t + i > MAXT) continue;
        if(check[t + i] != -1) { ans = check[t + i]; break;}
    }
    cout << ans << endl;
    
    return 0;
}