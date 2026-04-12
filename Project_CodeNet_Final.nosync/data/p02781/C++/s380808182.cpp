#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=105;
ll F[N][5],k;
string str;
vector <ll> B;
ll solve(ll pos,ll num,bool check)
{
    if(pos < 0) return num==k;
    if(check==true && F[pos][num] > -1) return F[pos][num];
    ll dem=0;
    for(int i=0;i<=max(check*9ll,B[pos]);i++)
    {
        if(i==0) dem+=solve(pos-1,num,check || (i < B[pos]));
        else
        {
            if(num==k) break;
            dem+=solve(pos-1,num+1,check || (i < B[pos]));
        }
    }
    if(check) F[pos][num]=dem;
    return dem;
}
ll calc(string str)
{
    while(str.size() > 0)
    {
        B.push_back(str[str.size()-1]-48);
        str.erase(str.size()-1,1);
    }
    return solve(B.size()-1,0,false);
}
int main()
{
    memset(F,-1,sizeof(F));
    cin>>str;
    cin>>k;
    cout<<calc(str);
    return 0;
}
