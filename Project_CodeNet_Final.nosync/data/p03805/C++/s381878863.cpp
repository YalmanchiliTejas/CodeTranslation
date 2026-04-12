#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI;typedef pair<ll,ll> pii;
const int mod = (int)1e9 + 7;

int n,m;
bool r[10][10];

int rec(int s, int u){
	
	int rtn =0;
	u |= 1<<s;
	if(u == (1<<n) - 1) return 1;
	rep(i,n) if(r[s][i] && !(u>>i &1)) rtn += rec(i, u);
	
	return rtn;
}


int main()
{
	
	//cin.tie(0); ios_base::sync_with_stdio(false);

	cin >>n >>m;
	rep(i,m){
		int a,b;
		cin >>a >>b;
		r[a-1][b-1]=r[b-1][a-1]=1;
	}
	
	cout << rec(0,0) <<endl;
	return 0;

}
