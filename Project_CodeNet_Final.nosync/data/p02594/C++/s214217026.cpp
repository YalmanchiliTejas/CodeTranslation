#include <iostream>
#include <string>
 
int main(){
 
const int MIN = -40;
const int MAX = 40;
const int THRES = 30;
std::string fStr = "";
std::cin >> fStr;
 
int fTemp = stoi(fStr);
if(fTemp < MIN|| fTemp > MAX){return -1;}
 
if(fTemp < THRES){std::cout<<"No" <<std::endl;}
else{std::cout<<"Yes"<<std::endl;}
 
return 0;
}
