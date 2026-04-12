#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#endif

const int MAXN = 1e5 + 100;

bool mk[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, X, M;
    cin >> N >> X >> M;

    int cont = 0;

    int sum = 0;

    int pt = X;

    for(int i = 1 ; i <= min(N, M) ; i++)
    {
    	if(mk[pt])
    	{
    		break;
    	}

    	mk[pt] = true;

    	sum += pt;
    	cont++;

    	pt = pt*pt % M;
    }

    N -= cont;

    db(pt);
    db(sum);
    db(cont);

    for(int i = 0 ; i < MAXN ; i++)
    {
    	mk[i] = false;
    }

    int sumtemp = 0;
    cont = 0;

    for(int i = 1 ; ; i++)
    {
    	if(mk[pt])
    	{
    		break;
    	}

    	mk[pt] = true;

    	sumtemp += pt;
    	cont++;

    	pt = pt*pt % M;
    }

    sum += (N/cont)*sumtemp;

    N %= cont;

    for(int i = 0 ; i < MAXN ; i++)
    {
    	mk[i] = false;
    }

    for(int i = 1 ; i <= N; i++)
    {
    	if(mk[pt])
    	{
    		break;
    	}

    	mk[pt] = true;

    	sum += pt;

    	pt = pt*pt % M;
    }

    cout << sum << '\n';

    return 0;
}