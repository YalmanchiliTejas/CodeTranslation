#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int data[300];
int main(){
	data['a'] = 0;
	data['b'] = 0;
	data['c'] = 0;
	data['d'] = 0;
	data['e'] = 0;
	data['f'] = 0;
	data['g'] = 0;
	data['h'] = 1;
	data['i'] = 1;
	data['j'] = 1;
	data['k'] = 1;
	data['l'] = 1;
	data['m'] = 1;
	data['n'] = 1;
	data['o'] = 1;
	data['p'] = 1;
	data['q'] = 0;
	data['r'] = 0;
	data['s'] = 0;
	data['t'] = 0;
	data['u'] = 1;
	data['v'] = 0;
	data['w'] = 0;
	data['x'] = 0;
	data['y'] = 1;
	data['z'] = 0;
	while(1){
		string tmp;
		cin >> tmp;
		if(tmp=="#") break;
		int old;
		old = data[tmp[0]];
		int cnt = 0;
		FOR(i,1,tmp.size()){
			if(old!=data[tmp[i]]){
				cnt++;
				old = data[tmp[i]];
			}
		}
		cout << cnt << endl;
	}

}