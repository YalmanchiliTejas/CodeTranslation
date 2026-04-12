#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int n,m,ans=0;
    cin >> n>>m;
    bool connect[8][8];
    m0(connect);
    
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a>>b;
        a--;
        b--;
        connect[a][b]=true;
        connect[b][a]=true;
    }

    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        v.at(i)=i;
    }
    
    do
    {
        if(v.at(0)!=0)
        {
            break;
        }
        bool ok = true;
        
        for(int i = 0; i < n-1; i++)
        {
            if(connect[v.at(i)][v.at(i+1)]== false)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            ans++;
        }
    }while(next_permutation(all(v)));
    

    cout << ans<<endl;

    return 0;
}