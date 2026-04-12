#include <iostream>

int main(){
    std::string right = "yuiophjklnm";
    std::string S;
    while(std::cin >> S, S != "#"){
        int prev = -1, res = 0;
        for(const auto &c : S){
            int which = right.find(c) != std::string::npos;
            if(prev == -1){
                prev = which;
            }else if(which != prev){
                ++res; prev = which;
            }
        }

        printf("%d\n", res);
    }
}