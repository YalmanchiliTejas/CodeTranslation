#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<random>
#include<math.h>
#include<limits.h>
#include<iterator>
#define rep(i,a) for(int i=0;i<a;i++)
#define nrep(i,a,b) for(int i=a;i<b;i++)
#define mrep(i,a) for(int i=a;i>=0;i--)
#define ll long long
#define vl vector<ll> 
#define vvl vector<vector<ll> > 
#define vb vector<bool> 
#define vvb vector<vector<bool> > 
#define INF 1123456789012345
using namespace std;

int main(){
	ll r, g, b; cin >> r >> g >> b;
	r *= 100;
	g *= 10;
	ll ans = r + g + b;
	if (!(ans % 4)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}