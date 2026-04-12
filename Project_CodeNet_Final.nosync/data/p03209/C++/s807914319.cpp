#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bun[52], patty[52];
ll ret;
vector <ll> layers;

void f(int level, ll x){
	if(level == 0){
		//if(x) ret++;
		return;
	}
	if(x == layers[level]){
		ret += patty[level];
		x = 0;
		return;
	}
	if(x == 0) return;
	x--;
	if(x == 0) return;
	if(x < layers[level - 1]){
		f(level - 1, x);
		return;
	}
	ret += patty[level - 1];
	x -= layers[level - 1];
	if(x == 0) return;
	x--;
	ret++;
	if(x == 0) return;
	if(x == layers[level]){
		ret += patty[level];
		x = 0;
		return;
	}
	if(x < layers[level - 1]){
		f(level - 1, x);
		return;
	}
	ret += patty[level - 1];
	x -= layers[level - 1];
	if(x == 0) return;
	x--;
	ret++;
	return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;
    patty[0] = 1;
    bun[0] = 0;
    layers.push_back(1);
    for(int i = 1; i <= n; i++){
    	patty[i] = 1 + 2 * patty[i - 1];
    	bun[i] = 2 + 2 * bun[i - 1];
    	layers.push_back(patty[i] + bun[i]);
    }
    f(n, x);
    cout << ret;
}
