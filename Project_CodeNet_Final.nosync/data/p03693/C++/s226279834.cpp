#include <iostream>

#define ERR_EXTERN(int_in) ((int_in > 9) || (int_in < 1))

int main(){
    int r, g, b;
    int maked_int;
    std::cin >> r >> g >> b;
    if(ERR_EXTERN(r) || ERR_EXTERN(g) || ERR_EXTERN(b)){
        std::cout << "Invalid range value!" << std::endl;
        return 1;}
    maked_int = (r * 100) + (g * 10) + b;
    if((maked_int%4)==0){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}