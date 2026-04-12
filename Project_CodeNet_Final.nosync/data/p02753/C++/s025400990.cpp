#include<bits/stdc++.h>
/*	#include <boost/math/common_factor.hpp>  boost::math::lcm(10,20) ---> use it to find lcm.*/
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
// #define int long long 
#define PI pair<int , int >
#define mpr make_pair
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define debug() cout << "Hi" << endl	// write debug(); in main()
const int MOD = 1e9+7;
const int MAXN = 1e5+3;
const int inf = 2e9;
int max(int a,int b){	if(a > b)return a; else return b; }
int min(int a, int b){	if(a < b)return a; else return b; }
/*		0. Go to main function first.
		1. Take all the inputs................................................
		2. Check Once whether the graph given is directed or undirected.......
		3. Tree can also be undirected.
		4. Whenever you do multiplication and division in the same line, beware.
*/
void solve(){
	//debug();
	// int main  or  int32_t main ...
	string s;
	cin >> s;
	int a=0,b=0;
	for(int i = 0;i < 3;++i){
		if(s[i] == 'A')a++;
		if(s[i] == 'B')b++;
	}
	if(a==0||b==0)cout << "No" << endl;
	else cout << "Yes" << endl;
}
/*	memset() can be used to set all values as 0 or -1 for integer data types.*/

int main(){
	IO;
	#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	// std::cout << std::setprecision(12); std::cout << std::fixed;
	int t;
	// cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}
