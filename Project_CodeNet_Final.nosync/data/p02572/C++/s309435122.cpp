/**
 *    author:  Mohamad Milhem
**/

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define MOD ll(1000000007)
#define debug(x) cout << '[' << #x << " is: " << x << "] " <<endl;
#define decimalpoint cout << std::fixed << setprecision(5)


void solve(){
	int n;
	cin >> n;
	vector<long long> v(n);
	long long sum = 0;


	lp(i, 0 , n){
		cin >> v[i];
		sum+= v[i];
	}


	long long bigsum = 0;
	long long already = 0;


	lp(i , 0 , n){
		already+= v[i];
		bigsum+= (sum - already)%MOD * v[i]%MOD;
		bigsum%=MOD;
	}	

	cout << bigsum << endl;

}



int main()
{
    FAST;
    int t;
    t = 1;

    while(t--){
        solve();
    }
    return 0;
}
