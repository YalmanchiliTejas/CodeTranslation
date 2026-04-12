
#include<bits/stdc++.h>
#define int ll

#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;

const int N = 1e5 + 10;
int hit[N + 2];

signed main(){

#ifndef ONLINE_JUDGE
	//freopen("in.txt" , "r" , stdin);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);


    int n , x , m;
    cin >> n >> x >> m;
    int f = x;
    hit[f] = 1; 
    vi before_cycle , cycle;
    int ss = f;
    for(int i = 1 ; i < n ; i++){
        f = (f * f) % m;
        if(hit[f] == 0)
        ss += f;
        if(f == 0){
            cout << ss << '\n';
            return 0;
        }
        if(hit[f] == 3)
            break;
        hit[f]++;
        if(hit[f] == 2)
            cycle.pb(f);
    }

    int ans = 0;
    //return 0;
    for(int i = 0 ; i < m ; i++)
        if(hit[i] == 1)
            ans += i , before_cycle.pb(i); 
    
    int sum = 0;
    for(int i : cycle)
        sum += i;

    int numOfHits = cycle.size();
    n -= before_cycle.size();
    n = max(n , 0LL);
    if(numOfHits)
        ans += sum * (n / numOfHits) , n %= numOfHits;

    for(int i = 0 ; i < n ; i++)
        ans += (long long)cycle[i];

    cout << ans << '\n';
    
    return 0;

}

