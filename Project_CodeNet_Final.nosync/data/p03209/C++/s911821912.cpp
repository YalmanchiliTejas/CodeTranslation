#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


ll n,x;
vl pat(55);
vl size(55);


ll solve(int lev, ll num){
	if(lev==0){
		if(num==1)
			return 1;
		else
			return 0;
	}
	else{
		if(num==1)
			return 0;
		else if(num<=size[lev-1]+1){
			return solve(lev-1,num-1);
		}
		else if(num==size[lev-1]+2){
			return pat[lev-1]+1;
		}
		else if(num<=size[lev-1]*2+2){
			return solve(lev-1, num-size[lev-1]-2)+pat[lev-1]+1;
		}
		else{
			return pat[lev-1]*2+1;
		}

	}

}

int main(){
	cin >> n >>x;
	pat[0]=1;
	size[0]=1;
	REP(i,1,55){
		pat[i]=pat[i-1]*2+1;
		size[i]=size[i-1]*2+3;
	}
	ll ans=solve(n,x);
	cout<<ans<<endl;
    return 0;
}