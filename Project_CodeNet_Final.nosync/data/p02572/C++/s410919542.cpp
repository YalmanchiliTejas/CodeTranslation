#include <bits/stdc++.h>
#define rep(i,N) for(int i = 0 ; i < int(N);i++)
using namespace std ;
typedef long long ll;
typedef pair <int , int >pi;
typedef vector <int> vi ;
typedef vector <string> si;

const ll mod = 1'000'000'007;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int sum = 0 ;
	int N ;
	cin >> N ;
	vector<int> v(N);
	int x = 0 ;
	rep(i,N){
		cin >> v[i];
	}
	rep(i,N){
		sum = (sum +((ll)v[i]*x))%mod;
		x = (x+v[i])%mod;
	}
	cout << sum << endl;

	return 0 ;
}