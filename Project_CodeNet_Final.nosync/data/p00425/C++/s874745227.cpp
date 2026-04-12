#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct dice_{
	int up;
	int down;
	int left;
	int right;
	int forward;
	int back;
};

dice_ rot_N(dice_ d){
	dice_ res = d;
	res.up = d.back;
	res.back = d.down;
	res.down = d.forward;
	res.forward = d.up;
	return res;
}

dice_ rot_S(dice_ d){
	dice_ res = d;
	res.up = d.forward;
	res.back = d.up;
	res.down = d.back;
	res.forward = d.down;
	return res;
}

dice_ rot_E(dice_ d){
	dice_ res = d;
	res.up = d.left;
	res.left = d.down;
	res.down = d.right;
	res.right = d.up;
	return res;
}

dice_ rot_W(dice_ d){
	dice_ res = d;
	res.up = d.right;
	res.left = d.up;
	res.down = d.left;
	res.right = d.down;
	return res;
}

dice_ rot_R(dice_ d){
	dice_ res = d;
	res.forward = d.left;
	res.left = d.back;
	res.back = d.right;
	res.right = d.forward;
	return res;
}

dice_ rot_L(dice_ d){
	dice_ res = d;
	res.forward = d.right;
	res.left = d.forward;
	res.back = d.left;
	res.right = d.back;
	return res;
}

dice_ dice;

int main(){
	int n, ans;
	string str;
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}
		dice.up = 1;
		dice.down = 6;
		dice.right = 3;
		dice.left = 4;
		dice.back = 2;
		dice.forward = 5;
		
		ans = 1;
		for(int i = 0; i < n; i++){
			cin >> str;
			if(str[0] == 'N'){
				dice = rot_N(dice);
			}else if(str[0] == 'S'){
				dice = rot_S(dice);
			}else if(str[0] == 'W'){
				dice = rot_W(dice);
			}else if(str[0] == 'E'){
				dice = rot_E(dice);
			}else if(str[0] == 'L'){
				dice = rot_L(dice);
			}else if(str[0] == 'R'){
				dice = rot_R(dice);
			}
			ans += dice.up;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}