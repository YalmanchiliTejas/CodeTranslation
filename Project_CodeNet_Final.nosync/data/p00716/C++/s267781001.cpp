#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#include <ctime>
#include <assert.h>
#include <chrono>
#include <random>
#include <numeric>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	while(n--){
		int a,b,c; cin >> a >> b >> c;
		int res=0;
		for(int i=0;i<c;i++){
			int e,g; double f; cin >> e >> f >> g;
			if(!e){
				int h=a;
				int v=0;
				for(int j=0;j<b;j++){
					v+=f*h;
					h-=g;
				}
				res=max(res,h+v);
			}
			else{
				int h=a;
				for(int j=0;j<b;j++){
					h=h+f*h-g;
				}
				res=max(res,h);
			}
		}
		printf("%d\n",res);
	}
}

