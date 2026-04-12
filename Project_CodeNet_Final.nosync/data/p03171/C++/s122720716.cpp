#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll a[3010];
ll dp[3010][3010];
bool mark[3010][3010];

ll resi(int levi,int desni, int igrac)
{
    if(levi==desni)
        return igrac==0?a[levi]:-a[levi];

    if(mark[levi][desni])
        return dp[levi][desni];

    mark[levi][desni]=true;

    if(igrac==0)
    {
        dp[levi][desni]=max(a[levi]+resi(levi+1,desni,1),a[desni]+resi(levi,desni-1,1));
        return dp[levi][desni];
    }
    else
    {
        dp[levi][desni]=min(-a[levi]+resi(levi+1,desni,0),-a[desni]+resi(levi,desni-1,0));
        return dp[levi][desni];
    }



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<resi(0,n-1,0);

	return 0;
}
