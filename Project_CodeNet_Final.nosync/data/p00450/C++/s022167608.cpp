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
	while(1){
	int n; cin >> n;
	if(!n)break;
	vector<pair<int,int>> v;
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		if(i%2){
			if(v.size()){
				if(v.back().first==x){
					v.back().second++;
				}
				else{
					v.push_back({x,1});
				}
			}
			else{
				v.push_back({x,1});
			}
		}
		else{
			if(v.back().first==x){
				v.back().second++;
			}
			else{
				int p=v.back().second+1;
				v.pop_back();
				if(v.size()){
					v.back().second+=p;
				}
				else{
					v.push_back({x,p});
				}
			}
		}
	}
	int res=0;
	for(auto p:v){
		if(p.first==0)res+=p.second;
	}
	printf("%d\n",res);
	}
}
