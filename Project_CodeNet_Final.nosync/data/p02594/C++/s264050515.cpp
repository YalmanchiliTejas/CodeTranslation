#include<iostream>
#include<vector>

#define rep(i, n) for(int i = 0; i < (n); i++)
using P = std::pair<int, int>;
using ll = long long ;
template<class T> inline void chmax(T& a, T b) {if(a < b) a = b; }
template<class T> inline void chmin(T& a, T b) {if(a > b) a = b; }

int main(){

	int n;
	std::cin >> n;
	if(n >= 30){
		std::cout << "Yes" << std::endl;
	}else{
		std::cout << "No" << std::endl;
	}

	return 0;
}