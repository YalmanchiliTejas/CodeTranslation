#include<iostream>
const char vow[]={'a','e','i','o','u'};
int main()
{
    char tin;
    std::cin>>tin;
    for(int i=0;i<5;i++){
        if(tin==vow[i]) {
            std::cout<<"vowel";
            return 0;
        } 
//what the fuck
    }
    std::cout<<"consonant";
    return 0;
}