#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int, int> pii;
const int mod = (int)1e9 +7;


int n,m;
vector<VI> r;
VI usd;
int rec(int z){
	//if(usd[z] !=0) return 0;
	usd[z] = 1;
	if(count(all(usd),1) ==n){
		usd[z]=0;
		return 1;
	}
	int rtn =0;
	rep(i,n) if(r[z][i]==1 && usd[i]==0) rtn += rec(i);
	usd[z] = 0;
	return rtn;
}


int main()
{
	
	//cin.tie(0); ios_base::sync_with_stdio(false);

	cin >>n >>m;
	usd.assign(n,0);
	r.assign(n, VI(n,0));
	rep(i,m){
		int a,b;
		cin >>a >>b;
		r[a-1][b-1]=r[b-1][a-1]=1;
	}
	
	cout << rec(0) <<endl;
	
	return 0;

}
