#include<iostream>
main(){std::string S;std::cin>>S;std::cout<<(~S.find(65)&~S.find(66)?"Yes":"No");}