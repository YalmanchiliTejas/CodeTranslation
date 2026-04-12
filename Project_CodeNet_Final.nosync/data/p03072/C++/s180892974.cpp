#include<iostream>

int main(){

    size_t n, cnt = 0;
    size_t h1;

    std::cin >> n;

    for(size_t i = 0; i < n; i++){
        if(i == 0){
            std::cin >> h1;
            cnt++;
        }else{
            size_t tmp;
            std::cin >> tmp;
            if(tmp == h1){
                cnt++;
            }else if(tmp > h1){
                cnt++;
                h1 = tmp;
            }
        }
    }

    std::cout << cnt << std::endl;
    
    return 0;
}
