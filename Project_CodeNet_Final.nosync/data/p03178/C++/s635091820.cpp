#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9+7;
const int M = 101;

vector<vector<int> > cur(M,vector<int>(2,0));
vector<vector<int> > nex(M,vector<int>(2,0));

int md[M][10],d;
string s;

signed main()
{
    fast;
    
    cin >> s >> d;
    
    int n = s.length();
    reverse(s.begin(),s.end());
    
    f(i,d) f(j,10)
        md[i][j] = ((i - j)%d + d)%d;
    
    cur[0][0] = cur[0][1] = 1;
    
    for(int i=1;i<=n;i++)
    {
        
    f(j,d)
    {
        nex[j][1] = nex[j][0] = 0;
        
        f(v,10)
            nex[j][1] = (nex[j][1] + cur[md[j][v]][1])%MOD;
        
        f(v,s[i-1]-'0')
            nex[j][0] = (nex[j][0] + cur[md[j][v]][1])%MOD;
        
        nex[j][0] = (nex[j][0] + cur[md[j][s[i-1]-'0']][0])%MOD;
    }
     
        swap(cur,nex);
    }
    
    cout << ( cur[0][0] - 1 + MOD)%MOD;
}