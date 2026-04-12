#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll x,y,z;
	cin >> x >> y >> z;
	ll i = 0;
	while(1){
		if (x >= (y*i +z*(i+1))){
			i++;
		}
		else{
			break;
		}
	}
	cout << i - 1 <<endl;

	return 0;
}