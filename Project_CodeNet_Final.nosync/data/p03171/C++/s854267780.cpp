#include<iostream>
#include<algorithm>

using namespace std;

const int NMAX = 3005;

//dp[i][j][k] = playing from ks perspective, the optimal play given the set a without [1..i] and [j..N]
//0 = Taro , 1 = Jiro
int N;
long long dp[NMAX][NMAX][2],a[NMAX];

inline long long DFS(int pref,int suf,int player)
{
    if(dp[pref][suf][player])
    {
        return dp[pref][suf][player];
    }
    else if(pref+suf == N)
    {
        dp[pref][suf][player] = 0;
        return dp[pref][suf][player];
    }
    else
    {
        long long v1,v2;
        DFS(pref+1 , suf , (player^1));
        DFS(pref , suf+1 , (player^1));
        if(player == 0)
        {
            v1 = a[pref+1] + dp[pref+1][suf][(player^1)];
            v2 = a[N-suf] + dp[pref][suf+1][(player^1)];
            dp[pref][suf][player] = max(v1,v2);
        }
        else
        {

            v1 = dp[pref+1][suf][(player^1)] - a[pref+1];
            v2 = dp[pref][suf+1][(player^1)] - a[N-suf];
            dp[pref][suf][player] = min(v1,v2);
        }
        return dp[pref][suf][player];
    }
}

int main()
{
    int i,j;
    cin>>N;

    for(i = 1 ; i <= N ; ++i)
        cin>>a[i];

    cout<<DFS(0,0,0);

}
