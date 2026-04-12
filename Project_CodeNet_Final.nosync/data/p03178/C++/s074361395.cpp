#include <bits/stdc++.h>
using namespace std;
const int base=1e9+7;
string k;
int d;
int m;
int f[10004][110][2];
bool kt[10004][110][2];
int F(int i,int mod,int ok)
{
    if (i==m) return mod==0;
    if (kt[i][mod][ok]) return f[i][mod][ok];
    int res=0;
    if (ok)
    {
        int x=int(k[i]-'0');
        for (int j=0;j<=x;j++)
        {
            if (j==x) res=(res+F(i+1,(mod+j)%d,1))%base;
            else res=(res+F(i+1,(mod+j)%d,0))%base;
        }
    }
    else for (int j=0;j<=9;j++)
        {
           res=(res+F(i+1,(mod+j)%d,0))%base;
        }
    kt[i][mod][ok]=true;
    f[i][mod][ok]=res%base;
    return res%base;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.inp", "r", stdin);
    //freopen("ou.out", "w", stdout);
    cin>>k;
    cin>>d;
    m=k.size();
    cout<<max(0,(F(0, 0,1) - 1 +base) %base);
    return 0;
}
