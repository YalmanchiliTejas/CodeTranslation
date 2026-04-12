#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#include<cassert>
#include<functional>
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	ll make_level;
	ll eat_layers;

	//プロトタイプ宣言
	ll layers(ll level);
	ll patties(ll level);
	ll ans(ll level, ll eat);

	std::cin >> make_level >> eat_layers;
	//入力終わり

	std::cout << ans(make_level, eat_layers) << '\n';

	return 0;
}

ll layers(ll level){
	if (level == 0)
		return 1;
	return layers(level - 1) * 2 + 3;
}

ll patties(ll level){
	if (level == 0)
		return 1;
	return patties(level - 1) * 2 + 1;
}

ll ans(ll level, ll eat){
	//終点
	if (level == 0){
		if (eat == 1)
			return 1;
		else
			return 0;
	}

	if (eat == 1){
		return 0;
	}
	else if (eat <= 1 + layers(level - 1)){
		return ans(level - 1, eat - 1);
	}
	else if (eat == 2 + layers(level - 1)){
		return patties(level - 1) + 1;
	}
	else if (eat <= 2 + layers(level - 1) * 2){
		return patties(level - 1) + 1 + ans(level - 1, eat - layers(level - 1) - 2);
	}
	else{
		return patties(level - 1) * 2 + 1;
	}
}