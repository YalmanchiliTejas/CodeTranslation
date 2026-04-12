#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stack>

#define ll long long
#define vl vector<ll>
#define vvl vector< vector<ll> >
#define vb vector<bool>
#define vbb vector< vector<bool> >
#define vs vector<string>
#define vc vector<char>
#define vvc vector< vector<char> >

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

using namespace std;



int main(){
	ll x, y, z; cin >> x >> y >> z;
	ll ans = (x-z) / (y + z);
	cout << ans << endl;
	return 0;
}