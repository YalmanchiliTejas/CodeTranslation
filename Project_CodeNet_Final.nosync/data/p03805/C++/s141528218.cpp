//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

int N,M;
vector<vector<int>> adj;

LL ans = 0;

void search(int now,int used){
	if(used==(1<<N)-1){
		//cout << "finish:" << now << endl;
		ans++;
	}
	for(int next : adj[now]){
		if(!((used>>(next-1))&1)){
			//cout << now <<"->" << next << endl;
			search(next,used + (1<<(next-1)));
		}
	}
}

void solve(){
	search(1,1);
}
 
int main(){
    cin >> N >> M;
    adj = vector<vector<int>>(N+1);
    for(int i=0;i<M;i++){
    	int a,b;cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
 
    solve();

    cout << ans << endl;
    return 0;
}