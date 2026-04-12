#include<iostream>
#include<vector>
#include<sstream>

int toInt(std::string s){
	std::stringstream ss(s);
	int i;
	ss >> i;
	return i;
}

bool isTrue(int n, std::string s){
	std::string _s;
	if(n % 3 == 0)_s += "Fizz";
	if(n % 5 == 0)_s += "Buzz";
	if(n % 3 == 0 || n % 5 == 0){
		return s == _s;
	}
	return n == toInt(s);
}

int main(){
	int m, n;
	while(std::cin >> m >> n, m){
		std::vector<int> pv;
		for(int i=1;i<=m;i++){
			pv.push_back(i);
		}
	
		bool locked = false;//1人になった時点で無視しよう
		int who = 0;

		for(int i=1;i<=n;i++){
			std::string str;
			std::cin >> str;
			if(locked){//もう，ひとり
				continue;
			}
			if(isTrue(i, str)){

			}else{
				pv.erase(pv.begin() + who);
				if(pv.size() == 1){
					locked = true;
				}
				who--;
			}
			who = (who + 1) % pv.size();
		}

		std::cout << pv[0];
		for(int i=1;i<pv.size();i++){
			std::cout << " " << pv[i];
		}
		std::cout << "\n";
	}
}