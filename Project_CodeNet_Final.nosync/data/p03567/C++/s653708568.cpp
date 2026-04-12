#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int main() {
	std::string st;
	std::cin >> st;
	int l = 0;
	if (st.find("A") != st.size() - 1)if (st[st.find("A") + 1] == 'C')++l;
	std::cout << (l == 0? "No" : "Yes")<< std::endl;
	 return 0;
}