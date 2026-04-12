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
	int r,g,b;
	cin >> r >> g >>b;
	int ans = 100*r + 10*g + b;
	if (ans % 4 == 0){
		cout << "YES" <<endl;
	}
	else{
		cout<< "NO" << endl;
	}
	return 0;
}