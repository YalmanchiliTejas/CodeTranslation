#include <iostream>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::string ans = "Yes";
    if(n != m){
        ans = "No";
    }

    std::cout << ans << std::endl;

    return 0;
}