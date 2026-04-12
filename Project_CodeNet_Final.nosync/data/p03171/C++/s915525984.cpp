#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll inf=1000000007;
const ll maxinput=3005;
const ll mod=998244353;
#define mp make_pair
ll n,a[maxinput];
pair <ll,ll> dp[maxinput][maxinput][2];
pair <ll,ll> optplay(ll i,ll j,ll player)
{
    if(i>j)
        return(mp(0,0));

    if(dp[i][j][player].first!=-1&&dp[i][j][player].second!=-1)
        return(dp[i][j][player]);
    if(player==0)
    {
        //return(max(a[i]+optplay(i+1,j,1),a[j]+optplay(i,j-1,1)));
        pair <ll,ll> temp1,temp2;
     
        temp1=optplay(i+1,j,1); temp2=optplay(i,j-1,1);
        if(a[i]+temp1.first-temp1.second>a[j]+temp2.first-temp2.second)
            return(dp[i][j][player]=mp(a[i]+temp1.first,temp1.second));
        else
            return(dp[i][j][player]=mp(a[j]+temp2.first,temp2.second));
    }
    else
    {
        pair <ll,ll> temp1,temp2;
     
        temp1=optplay(i+1,j,0); temp2=optplay(i,j-1,0);
        if(temp1.first-a[i]-temp1.second<temp2.first-a[j]-temp2.second)
            return(dp[i][j][player]=mp(temp1.first,a[i]+temp1.second));
        else
            return(dp[i][j][player]=mp(temp2.first,a[j]+temp2.second));
    }
}
int main()
{
    for(int i=0;i<maxinput;i++)
        for(int j=0;j<maxinput;j++)
            dp[i][j][0]=mp(-1,-1),dp[i][j][1]=mp(-1,-1);

    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    
    pair <ll,ll> xy=optplay(0,n-1,0); //optplay[i][j] is the result of play when the ends are i,j and 0 if its taro's turn and 1 if its jiro
    cout<<xy.first-xy.second<<"\n";

}