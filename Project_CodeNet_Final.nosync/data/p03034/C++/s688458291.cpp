#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;


int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    ll S[MN];
    for(int i=0; i<N; i++){
    	cin >> S[i];
    }
    ll ans = 0;
    for(int d=1; d<=N-1; d++){
    	ll val = 0;
    	for(int k=1; k<=N; k++){
    		ll A = N-1-d*k;
    		ll B = A-d;
    		if(A<0||B<0||B>=A) break;
    		if((N-1)%d==0&&(N-1)/d<=2*k) break;
    		val += S[d*k];
    		val += S[N-1-d*k];
    		ans = max(ans,val);
    	}
    }
    cout << ans;
}