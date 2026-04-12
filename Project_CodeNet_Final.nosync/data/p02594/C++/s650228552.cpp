/////////////////////////////////TEST CASES////////////////////////////////////
/*

*/
/////////////////////////////////////CODE/////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = a ; i > b ; i--)
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI 3.14159265
typedef long long ll;
#define VL vector<ll> 
#define IN(inp) ll inp;cin>>inp;
#define pb push_back
#define all(a) a.begin(),a.end()
#define what(A) cout<<#A<<" is "<<A<<endl;
ll MAX = 1000000000;
ll MOD = 1000000007;
int main()
{
	fastio
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	ll test = 1;
	//cin>>test;
	while (test--)
	{
		IN(n);
        if(n>=30)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
	}
}