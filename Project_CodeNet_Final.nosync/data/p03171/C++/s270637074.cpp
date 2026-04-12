#include <bits/stdc++.h>

using namespace std;


#define uniq(x)  x.erase(unique(x.begin(),x.end()), x.end()) //Unique value find from vector
#define upper(arr,n,fixed) upper_bound(arr,arr+n,fixed)-arr  //Upper value search  >
#define lower(arr,n,fixed) lower_bound(arr,arr+n,fixed)-arr  //Lower value search  >=
#define FOR(i,a,n) for(int i=a; i<(int)n; i++)
#define FORI(i,a,n) for(int i=a; i>=(int)n; i--)
#define pii pair<LL,LL>
#define vpii vector<pii>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(a) int((a).size())
#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define all(a) a.begin(), a.end()
#define MEMSET(p,i) memset(p,i,sizeof(p))

typedef long long LL;
typedef unsigned long long ULL;

pii memo[3010][3010];
LL v[3010];
int n;

pii dp(int i, int j)
{
	auto &dpm = memo[i][j];
	if(dpm != mp((LL)-1,(LL)-1))
		return dpm;
	if(i == j){
		if(n%2 == 0){
			dpm = {0,v[i]};
			
			return dpm;
		}
		else
			return dpm = {v[i],0};
	}

	auto x = dp(i+1,j);
	auto y = dp(i,j-1);

	if((j-i+1)%2 == 0){
		if(n%2 == 0){  // maximiza fi
			x.fi += v[i];
			y.fi += v[j];

			if(x.fi-x.se > y.fi-y.se)
				dpm = x;
			else
				dpm = y;

		}
		else{  // minimiza se
			x.se += v[i];
			y.se += v[j];

			if(x.fi-x.se < y.fi-y.se)
				dpm = x;
			else
				dpm = y;
		}
	}
	else{
		if(n%2 == 0){  // minimiza se
			x.se += v[i];
			y.se += v[j];

			if(x.fi-x.se < y.fi-y.se)
				dpm = x;
			else
				dpm = y;
		}
		else{// maximiza fi
			x.fi += v[i];
			y.fi += v[j];

			if(x.fi-x.se > y.fi-y.se)
				dpm = x;
			else
				dpm = y;
			}
	}
	// cout << i+1 << " " << j+1 << " " << dpm.fi << " " << dpm.se << endl;
	return dpm;
}
int main(void)
{
	fastIO();

	cin >> n;
	FOR(i,0,n)
		cin >> v[i];

	FOR(i,0,n)
		FOR(j,0,n)
			memo[i][j] = mp(-1,-1);

	pii ans = dp(0,n-1);
	cout << ans.fi - ans.se << endl;


	
	
}