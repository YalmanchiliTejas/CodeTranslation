#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 2010;

int A[3*MAXN];

int acum = 0;

int dp[MAXN][MAXN];

struct dpp
{
	int x, y, v;
};

int may[MAXN];

int mayg;

bool mk[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0 ; i < MAXN ; i++)
    {
    	for(int j = 0 ; j < MAXN ; j++)
    	{
    		dp[i][j] = -1e18;
    	}
    }

    int N;
    cin >> N;

    for(int i = 1 ; i <= 3*N ; i++)
    {
    	cin >> A[i];
    }

   	dp[A[1]][A[2]] = 0;
   	dp[A[2]][A[1]] = 0;

    // for(int i = 1 ; i <= 3 ; i++)
    // {
    // 	for(int j = 1 ; j <= 3 ; j++)
    // 	{
    // 		cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n'; 
    // 	}
    // }

    // cout << '\n';
   	
   	mayg = 0;

    may[A[1]] = 0;
    may[A[2]] = 0;

    for(int i = 1 ; i <= N-1 ; i++)
    {
    	int a = A[i*3], b = A[i*3+1], c = A[i*3+2];

    	vector<dpp> vect;

    	int tp = 0;

    	if(a == b && b == c)
    	{
    		acum++;
    		tp = 1;
    	}
    	if(1)
    	{
    		if(a == b)
	    	{
	    		for(int j = 1 ; j <= N ; j++)
	    		{
	    			vect.push_back({j,c,max(dp[j][c], dp[a][j] + 1)});
	    			vect.push_back({c,j,max(dp[c][j], dp[a][j] + 1)});
	    		}
	    	}
	    	if(a == c)
	    	{
	    		for(int j = 1 ; j <= N ; j++)
	    		{
	    			vect.push_back({j,b,max(dp[j][b], dp[a][j] + 1)});
	    			vect.push_back({b,j,max(dp[b][j], dp[a][j] + 1)});
	    		}
	    	}
	    	if(b == c)
	    	{
	    		for(int j = 1 ; j <= N ; j++)
	    		{
	    			vect.push_back({j,a,max(dp[j][a], dp[b][j] + 1)});
	    			vect.push_back({a,j,max(dp[a][j], dp[b][j] + 1)});
	    		}
	    	}

	    	vect.push_back({b,c,max(dp[b][c], dp[a][a] + 1)});
	    	vect.push_back({c,b,max(dp[c][b], dp[a][a] + 1)});

	    	vect.push_back({a,c,max(dp[a][c], dp[b][b] + 1)});
	    	vect.push_back({c,a,max(dp[c][a], dp[b][b] + 1)});

	    	vect.push_back({a,b,max(dp[a][b], dp[c][c] + 1)});
	    	vect.push_back({b,a,max(dp[b][a], dp[c][c] + 1)});
    	}

    	for(int j = 1 ; j < i*3 ; j++)
    	{
    		vect.push_back({A[j],a,max(dp[A[j]][a], may[A[j]])});
    		vect.push_back({a,A[j],max(dp[a][A[j]], may[A[j]])});
    	}

    	for(int j = 1 ; j < i*3 ; j++)
    	{
    		vect.push_back({A[j],b,max(dp[A[j]][b], may[A[j]])});
    		vect.push_back({b,A[j],max(dp[b][A[j]], may[A[j]])});
    	}

    	for(int j = 1 ; j < i*3 ; j++)
    	{
    		vect.push_back({A[j],c,max(dp[A[j]][c], may[A[j]])});
    		vect.push_back({c,A[j],max(dp[c][A[j]], may[A[j]])});
    	}

    	vect.push_back({a,b,mayg});
    	vect.push_back({a,c,mayg});
    	vect.push_back({b,c,mayg});

    	for(auto x : vect)
    	{
    		mayg = max(mayg, x.v-tp);
    		may[x.x] = max(may[x.x], x.v-tp);

    		dp[x.x][x.y] = max(dp[x.x][x.y], x.v - tp);
    	}
    }

    int res = 0;

    for(int i = 0 ; i < MAXN ; i++)
    {
    	for(int j = 0 ; j < MAXN ; j++)
    	{
    		dp[i][j] += acum;

    		if(A[3*N] == i && i == j)res = max(res, dp[i][j]+1);
    		else res = max(res, dp[i][j]);
    	}
    }

    // for(int i = 1 ; i <= 3 ; i++)
    // {
    // 	for(int j = 1 ; j <= 3 ; j++)
    // 	{
    // 		cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n'; 
    // 	}
    // }

    cout << res << '\n';

    return 0;
}