#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

signed main() {
    string k;
    int d;
    cin>>k>>d;
    vector<int> dp0(d,0),dp1(d,0);
    dp0[0] = 1;
    for(int i=0;i<k.size();i++)
    {
        vector<int> dp2(d,0),dp3(d,0);
    

        for(int i1=0;i1<d;i1++)
        {
            for(int j=0;j<=9;j++)
            {
                (dp3[(i1+j)%d] += dp1[i1]) %=P;
            }
            for(int j=0;j<=(k[i] - '0');j++)
            {    if(j <(k[i] - '0'))
                (dp3[(i1+j)%d] += dp0[i1]) %=P;
                else
                (dp2[(i1+j)%d] += dp0[i1]) %=P;
            }
        }
        
        dp1 = dp3;
        dp0 = dp2;
    }
    cout<<(dp1[0] + dp0[0] -1 + P)%P;
    return 0;
}