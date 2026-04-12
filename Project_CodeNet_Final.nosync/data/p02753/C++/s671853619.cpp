#include <iostream>

int main(){
    char S[3];
    for(int i=0;i<3;i++){
        std::cin>>S[i];
    }

    if(S[0]==S[1]&&S[1]==S[2]){
        std::cout<<"No";
    }else{
        std::cout<<"Yes";
    }
}