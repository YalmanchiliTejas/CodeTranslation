#include<bits/stdc++.h>
using namespace std;
int ans = 0;
vector<int> v;
int m;
int DP[10009][2][101][2];
int N = 1000000007;
int dp(int pos,int isSmall,int mod,int leadingZero)
{

    if(DP[pos][isSmall][mod][leadingZero]!=-1)
    {
        return DP[pos][isSmall][mod][leadingZero];
    }
    //cout<<pos<<" "<<isSmall<<" "<<mod<<" "<<leadingZero<<endl;
    if(pos==v.size())
    {
        if(mod==0 && leadingZero==1)
            return DP[pos][isSmall][mod][leadingZero] = 1;
        else return DP[pos][isSmall][mod][leadingZero] = 0;

    }
    DP[pos][isSmall][mod][leadingZero] = 0;
    if(isSmall==0)
    {
        for(int i=0;i<v[pos];i++)
        {
            if(i==0)
                DP[pos][isSmall][mod][leadingZero] = (DP[pos][isSmall][mod][leadingZero] +dp(pos+1,1,(mod+i)%m,leadingZero|0))%N;
            else
                DP[pos][isSmall][mod][leadingZero] = (DP[pos][isSmall][mod][leadingZero]+dp(pos+1,1,(mod+i)%m,1))%N;
        }
        if(v[pos]==0)
            DP[pos][isSmall][mod][leadingZero] = (DP[pos][isSmall][mod][leadingZero]+dp(pos+1,0,(mod+v[pos])%m,leadingZero|0))%N;
        else
            DP[pos][isSmall][mod][leadingZero] = (DP[pos][isSmall][mod][leadingZero]+dp(pos+1,0,(mod+v[pos])%m,1))%N;
    }
    else
    {
        DP[pos][isSmall][mod][leadingZero] = (DP[pos][isSmall][mod][leadingZero]+dp(pos+1,1,(mod+0)%m,leadingZero|0))%N;
        for(int i=1;i<10;i++)
            DP[pos][isSmall][mod][leadingZero] = (DP[pos][isSmall][mod][leadingZero]+ dp(pos+1,1,(mod+i)%m,1))%N;
    }
    return DP[pos][isSmall][mod][leadingZero];
}
int main()
{
    string n;
    cin>>n>>m;
    memset(DP,-1,sizeof DP);
    for(int i=0;i<n.size();i++)
        v.push_back(n[i]-48);

    cout<<dp(0,0,0,0)<<endl;

}
