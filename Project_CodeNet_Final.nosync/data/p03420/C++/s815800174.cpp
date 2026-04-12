#include <bits/stdc++.h>
#define fore(x,a,b) for(int x=a, qwerty=b; x<qwerty; x++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fst first
#define snd second
using namespace std;
typedef long long ll;

ll n, k;
ll ans = 0;
int main(){
	cin >> n >> k;
	for(int b=k+1; b<=n; b++){
	    int last=0, cnt=0;
	    for(int y=b; y<=n; y+=b){
	        ans += b - k;cnt+=b-k;
	        last = y;
	    }
	    int tmp = n-last;
	    tmp = max(0LL,tmp-k+1);cnt+=tmp;
	    ans += tmp;
	    if(k==0)ans--;
	}
	cout << ans << "\n";
}