#include<iostream>
std::string s;
int main(){
	std::cin>>s;
	std::cout<<(s.find("AC")==-1?"No\n":"Yes\n");
}