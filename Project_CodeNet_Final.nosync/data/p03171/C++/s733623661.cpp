    #include<bits/stdc++.h>
    #include<math.h>

    typedef long long int ll;
    #define pb         push_back
    #define mp         make_pair
    #define F          first
    #define S          second
    #define fl(i,a,b)  for(ll i=a;i<b;i++)
    #define pll        pair<ll,ll>
    #define pii        pair<int,int>
    #define all(v)     v.begin(),v.end()
    #define M 1000000007
    #define tr(v, it) for(auto it = v.begin(); it != v.end(); it++)
    using namespace std;
bool visited[3009][3009]={false};
pair<ll,ll> dp[3009][3009];
pair<ll,ll> dfs(int i,int j, ll arr[])
{

    if(i==j)
    {
        visited[i][j]=true;
        // cout<<i<<" "<<j<<" "<<dp[i][j].first<<" "<<dp[i][j].second<<"\n";
        return dp[i][j];
    }
    visited[i][j]=true;


        if(!visited[i+1][j] && !visited[i][j-1])
        {
                if(arr[i]+dfs(i+1,j,arr).second>=arr[j]+dfs(i,j-1,arr).second)
                    dp[i][j]=mp((arr[i]+dp[i+1][j].second),dp[i+1][j].first);
                else
                    dp[i][j]=mp((arr[j]+dp[i][j-1].second),dp[i][j-1].first);
        }

        else if(visited[i+1][j] && !visited[i][j-1])
        {
            if((arr[i]+dp[i+1][j].second)>=arr[j]+dfs(i,j-1,arr).second)
                dp[i][j]=mp((arr[i]+dp[i+1][j].second),dp[i+1][j].first);
            else
                dp[i][j]=mp((arr[j]+dp[i][j-1].second),dp[i][j-1].first);
        }
         else if(!visited[i+1][j] && visited[i][j-1])
        {
            if(arr[i]+dfs(i+1,j,arr).second>=(arr[j]+dp[i][j-1].second))
                dp[i][j]=mp((arr[i]+dp[i+1][j].second),dp[i+1][j].first);
            else
                dp[i][j]=mp((arr[j]+dp[i][j-1].second),dp[i][j-1].first);
        }
        else
        {
            if((arr[i]+dp[i+1][j].second)>=(arr[j]+dp[i][j-1].second))
                dp[i][j]=mp((arr[i]+dp[i+1][j].second),dp[i+1][j].first);
            else
                dp[i][j]=mp((arr[j]+dp[i][j-1].second),dp[i][j-1].first);
        }


  //  cout<<i<<" "<<j<<" "<<dp[i][j].first<<" "<<dp[i][j].second<<"\n";
    return dp[i][j];
}
    int main()
    {

        ios_base::sync_with_stdio(false);
    	cin.tie(NULL);

        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

       for(int i=0; i<n; i++)
        dp[i][i]=mp(arr[i],0);

        pair<ll,ll> p =dfs(0,n-1,arr);
        cout<<p.first-p.second;

       return 0;
    }
