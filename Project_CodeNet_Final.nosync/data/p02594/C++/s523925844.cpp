#include <iostream>


int main(){

    int temparature;

    std::cin >> temparature;

    if(40 < temparature || -40 > temparature){ return 0;}

    if(temparature >= 30){
        std::cout << "Yes";
    }else{
        std::cout << "No";
    }

}