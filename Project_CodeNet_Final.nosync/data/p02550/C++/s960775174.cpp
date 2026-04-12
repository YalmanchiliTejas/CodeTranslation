#include<bits/stdc++.h>
 
using namespace std;
 
#define D(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;

lli cnt[200005];
 
int main()
{
    lli n, x, m;
    cin >> n >> x >> m;
    lli ans = x;
    cnt[x] = 1;
    n--;
    while(n){
		x = (x*x)%m;
		if( cnt[x] ){
			break;
		}
		cnt[x]++;
		ans += x;
		
		n--;
	}
	if(n == 0 ){
		cout << ans << endl;
		return 0;
	}
	vector<lli> v;
	v.push_back(x);
	while(1){
		x = (x*x)%m;
		if(cnt[x] == 2) break;
		
		
		v.push_back(x);
		cnt[x]++;
	}
	v.pop_back();
	lli si = v.size();
	lli div = n/si;
	lli mod = n%si;
	//for(lli fx: v) cout << fx << endl;
	//D(si)D(div)D(mod)
	for(int i=0; i<si; i++){
		ans += (v[i]*div);
		if(i<mod){
			ans += v[i];
		}
	}
	cout << ans << endl;
 
    return 0;
}
