/*
 * 
 * Author : yash1402_
 * 
*/

#include <bits/stdc++.h>
 
using namespace std;

typedef long long int lli;
typedef vector<lli> vlli;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<lli,lli>> vplli;
typedef pair<lli,lli> plli;

#define rep(_I,_A,_B) for(lli _I=_A;_I<_B;_I++)

#define opv(_VAR) cout << #_VAR << ":" << _VAR << "\n";
#define opvec(_VEC) cout << #_VEC << ":"; for(auto _ELE:_VEC) cout << _ELE << " "; cout<<"\n";
 
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define B begin()
#define E end()
#define A assign
#define S size()

#define ipa(_VEC) for(auto &_ITER:_VEC) cin>>_ITER;
#define all(_VEC) _VEC.B,_VEC.E

void solve(){
	lli temp;
	cin >> temp;
	
	if(temp >= 30) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	lli t=1;
	//cin>>t;
	rep(tt,1,t+1){
		solve();
	}
}

