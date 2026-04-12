#include<bits/stdc++.h>
using namespace std;

long long N, X;


long long lenmemo [55];
long long getlen(long long layer){
	if(layer == 0){
		return 1;
	}
	if(lenmemo[layer] != 0){
		return lenmemo[layer];
	}
	lenmemo[layer] = 3 + 2*getlen(layer-1);
	return lenmemo[layer];
}

long long patimemo[55];
long long getpati(long long layer){
	if(layer == 0){
		return 1;
	}
	if(patimemo[layer] != 0){
		return patimemo[layer];
	}
	patimemo[layer] = 1 + 2*getpati(layer-1);
	return patimemo[layer];
}

long long eat(long long len, long long layer){
	if(len == 1){
		if(layer == 0){
			return 1;
		} else {
			return 0;
		}
	}
	long long nextlayer_len = getlen(layer - 1);
	//最初のl-1 layerの途中
	if(len < nextlayer_len + 1){
		return eat(len-1, layer-1);
	}
	//最初のl-1 layerを食べきるところ
	if(len == nextlayer_len + 1){
		return getpati(layer-1);
	}
	//最初のl-1 layerと真ん中のパティまで
	if(len == nextlayer_len + 2){
		return 1 + getpati(layer-1);
	}

	//2つ目ののl-1 layerの途中
	if(len < 2 * nextlayer_len  + 2){
		return 1 + getpati(layer-1) + eat(len - nextlayer_len - 2, layer - 1);
	}
	//2つ目ののl-1 layerの食べ終わり
	if(len == 2 * nextlayer_len  + 2){
		return 1 + 2* getpati(layer-1);
	}
	//2つ目ののl-1 layerの食べ終わり + 最後のban
	if(len == 2 * nextlayer_len  + 3){
		return 1 + 2* getpati(layer-1);
	}
	exit(1);
}

int main(){
	cin >> N >> X;
	cout << eat(X, N) << endl;
}
