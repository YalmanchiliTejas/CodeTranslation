#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vi = vector<int>;
using vvi = vector<vi>;
#define ote(x) cout<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define rpz(i,e) rp(i,0,e)

int main(){
	int X,Y,Z;
	cin>>X>>Y>>Z;
	int ans = X/(Y+Z);
	if(ans*(Y+Z)+Z > X){
		ote(ans-1);
	}
	else{
		ote(ans);
	}
}
