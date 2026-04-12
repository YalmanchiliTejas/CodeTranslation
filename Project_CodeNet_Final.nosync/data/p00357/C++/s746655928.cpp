#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
int n;
std::vector<int> d;
int main(){
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int tmp;
		std::cin >> tmp;
		d.push_back(tmp/ 10);
	}
	bool flag = true;
	int st = 0;
	for(int i = 0; i < n - 1; i++){
		st = std::max(st, d[i]);
		if(st <= 0)flag = false;
		st--;
	}
	if(st < 0)flag = false;	
	st = 0;
	std::reverse(d.begin(), d.end());
	for(int i = 0; i < n - 1; i++){
		st = std::max(st, d[i]);
		if(st <= 0)flag = false;
		st--;
	}
	if(st < 0)flag = false;
	std::cout << (flag ? "yes" : "no") << std::endl;
	return 0;
}
