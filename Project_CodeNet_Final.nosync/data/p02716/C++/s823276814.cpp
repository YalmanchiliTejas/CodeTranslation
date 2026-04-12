#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n+1,0);
    for(int i=1;i<=n;i++) cin >> v[i];
    map<int,ll> m[n+1];
    m[0][0]=0;
    m[1][1]=v[1];
    for(int i=1;i<=n;i++)
    {
        for(int c=max(1,(i+1)/2-10);c<=(i+1)/2;c++)
        {
            if(m[i].find(c)==m[i].end()) m[i][c]=-(1ll<<60);
            for(int j=max(0,i-4);j<i-1;j++)
            {
                if(m[j].find(c-1)==m[j].end()) continue;
                m[i][c]=max(m[i][c],m[j][c-1]+v[i]);
            }
        }
    }
    ll res=-(1ll<<60);
    for(int i=1;i<=n;i++) if(m[i].find(n/2)!=m[i].end()) res=max(res,m[i][n/2]);
    cout << res << endl;
    return 0;
}
