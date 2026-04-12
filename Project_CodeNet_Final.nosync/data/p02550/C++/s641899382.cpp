#include <bits/stdc++.h>
#define pb push_back
#define ll unsigned long long
#define mp make_pair
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0) 
#define sz(a) (a).size()
#define triple pair<pill, ll>
#define pinode pair<node*, node*>
#define quadra pair<pill, pill>
using namespace std;
 
/*
 tips :
 Sqrt opt
 Binary search
 Try to find the easiest solution
 Recursiya
 FUCK YOU pishi kod akuratnee daun yobani
 sdohni v adu nahui blyat' y ub'uy tebya
 esli ti blyad' budesh pisat' kod gryaznim
 to ya tebya v rot viebu
*/
 
const ll N = 1E6 + 10;
const ll M = 3e3 + 10;
const ll big = 1e18;
const ll shift = 1000;
const ll block = 500;
const ll has = 200123140004043;

const ll mod = 998244353;

mt19937 srnd(chrono::steady_clock::now().time_since_epoch().count()); 

ll n, x, m, sub;
ll p[N], s[N];

ll was[N];
int main() {
    speed;
	cin >> n >> x >> m;
	p[1] = x, was[x] = 1;
	s[1] = x;
	for(int i = 2; i <= 100000; i++) {
		p[i] = p[i - 1] * p[i - 1] % m;
		s[i] = s[i - 1] + p[i];
		if(p[i] == 0) 
			cout << s[i],ex;		 	
		if(was[p[i]]) {
			ll ans = s[was[p[i]] - 1];
			ll x = n - was[p[i]] + 1;
			ll sz = i - was[p[i]];
			ll z = s[i - 1] - s[was[p[i]] - 1];			 	            	
			ll y = s[was[p[i]] + (x % sz) - 1] - s[was[p[i]] - 1];
			cout << y + ans + (x / sz) * z, ex;
		}
		was[p[i]] = i;
	}
}             
                     
 
/*
6 0
1 2 4 6 8 10
1 4  d
*/ 