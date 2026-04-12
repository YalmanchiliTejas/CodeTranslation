#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;
#define INF	100000000
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define SS stringstream
#define rep(i,n) for(int i = 0; i < n; i++)
#define SORT(x) sort((x).begin(), (x).end())
#define clr(a,b) memset((a),(b),sizeof(a))
typedef long long int ll;
typedef pair<char, int> P;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<P> Vp;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

int main(){
	char t;
	while(cin >> t){
		P c[4][13];
		int fp = 0;
		int ns = 0, ew = 0;
		if(t == '#') break;
		rep(i,4) rep(j,13){
			int num = 0;
			string str;
			cin >> str;
			c[i][j].fi = str[1];
			if(str[0] == 'T') c[i][j].sec = 10;
			else if(str[0] == 'J') c[i][j].sec = 11;
			else if(str[0] == 'Q') c[i][j].sec = 12;
			else if(str[0] == 'K') c[i][j].sec = 13;
			else if(str[0] == 'A') c[i][j].sec = 14;
			else c[i][j].sec = str[0]-'0';
		}
		rep(i,13){
			bool x = false;
			int tmp = 0;
			rep(j,4) if(c[j][i].fi == t) x = true;
			if(x){
				rep(j,4){
					if(c[j][i].fi != t) continue;
					if(tmp < c[j][i].sec){
						fp = j;
						tmp = c[j][i].sec;
					}
				}
			} else{
				rep(j,4){
					if(c[j][i].fi != c[fp][i].fi) continue;
					if(tmp < c[j][i].sec){
						fp = j;
						tmp = c[j][i].sec;
					}
				}
			}
			if(fp%2) ew++;
			else ns++;
		}
		if(ns > ew) cout << "NS " << ns-6 << endl;
		else cout << "EW " << ew-6 << endl;
	}
}