#include <iostream>
#include <string>
using namespace std;
int main(void){
    int a,k;
    string s;
    std::cin>>a>>s>>k;
    for(int i=0;i<a;i++){
        if(s[k-1]!=s[i]){
            s[i]='*';
        }
    }
        std::cout <<s<< std::endl;
}
