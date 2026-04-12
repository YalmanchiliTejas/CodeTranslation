#include <iostream>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main(){
    std::string a;
    int flag = 0;

    // 入力
    std::cin >> a;


    rep(i, a.size()-1){
        if(a[i] != a[i+1]){
            flag = 1;
        }
    }

    if(flag == 0) std::cout << "No" << std::endl;
    else if(flag == 1) std::cout << "Yes" << std::endl;


    return 0;
}