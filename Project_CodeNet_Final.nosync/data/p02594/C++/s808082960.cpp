#include<iostream>

int main (){
    std::cin.tie(0); 
	std::ios::sync_with_stdio(false);
    int X;std::cin >> X;
    std::string ans="No";

    if (X >= 30) {
        ans="Yes";
    }

    std::cout << ans;

    return 0 ;
}
