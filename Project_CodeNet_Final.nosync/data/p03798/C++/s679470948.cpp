#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define ll long long
#define INF (1 << 30)
#define INFLL (1LL << 60)

#define FOR(i,a,b) for(ll i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

int loop[100010] = {};	//1=S, -1=W
int n;
string str;

bool check(){
	for(int i = 1;i < n;i++){
		if(str[i] == 'o'){
			if(loop[i] == 1){
				loop[i+1] = loop[i-1];
			}else{
				loop[i+1] = -loop[i-1];
			}
		}else{
			if(loop[i] == 1){
				loop[i+1] = -loop[i-1];
			}else{
				loop[i+1] = loop[i-1];
			}
		}
	}
	bool ret = true;
	if(loop[0] == 1){
		if(loop[1] != loop[n-1] && str[0] == 'o') ret = false;
		if(loop[1] == loop[n-1] && str[0] == 'x') ret = false;
	}else{
		if(loop[1] == loop[n-1] && str[0] == 'o') ret = false;
		if(loop[1] != loop[n-1] && str[0] == 'x') ret = false;
	}

	if(loop[n-1] == 1){
		if(loop[0] != loop[n-2] && str[n-1] == 'o') ret = false;
		if(loop[0] == loop[n-2] && str[n-1] == 'x') ret = false;
	}else{
		if(loop[0] == loop[n-2] && str[n-1] == 'o') ret = false;
		if(loop[0] != loop[n-2] && str[n-1] == 'x') ret = false;
	}

	return ret;
}

bool solve(){
	bool ans = false;
	loop[0] = 1;loop[1] = 1;
	ans = check();
	if(ans) return true;

	loop[0] = 1;loop[1] = -1;
	ans = check();
	if(ans) return true;

	loop[0] = -1;loop[1] = 1;
	ans = check();
	if(ans) return true;

	loop[0] = -1;loop[1] = -1;
	ans = check();
	if(ans) return true;

	return false;
}

int main() {
	cin >> n >> str;

	bool ret = solve();
	if(ret){
		for(int i = 0;i < n;i++){
			if(loop[i] == -1){
				cout << "W";
			}else{
				cout << "S";
			}
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}