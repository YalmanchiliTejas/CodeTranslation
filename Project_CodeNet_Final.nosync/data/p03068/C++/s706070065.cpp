#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){
	int n, k;
	std::string s;
	std::cin >> n >> s >> k;
	char s1 = s[k-1];
	for(int i=0; i<n; i++){
		if(s[i]!=s1) s[i] = '*';
		std::cout << s[i];
	}
	std::cout <<std::endl;
	return 0;
}
