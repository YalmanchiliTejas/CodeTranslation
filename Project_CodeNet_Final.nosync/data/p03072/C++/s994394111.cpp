#include<iostream>

int n,h,max=0,res=0;

int main(){

    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cin>>h;
        if(max<=h){
            max=h;
            res++;
        }
    }

    std::cout<<res<<std::endl;

    return 0;

}