#include<iostream>
#include<stack>
#include<vector>
#include<string>

std::vector<std::stack<char> >s;

void push(int p,char c){
	s[p-1].push(c);
}

void pop(int p){
	std::cout<<s[p-1].top()<<std::endl;
	s[p-1].pop();
}

void move(int p,int p1){
	s[p1-1].push(s[p-1].top());
	s[p-1].pop();
}

int main(){
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)s.push_back(std::stack<char>());
	std::string str;
	int p,p1;
	char c;
	std::cin>>str;
	while(str!="quit"){
		if(str=="push"){
			std::cin>>p>>c;
			push(p,c);
		}
		if(str=="pop"){
			std::cin>>p;
			pop(p);
		}
		if(str=="move"){
			std::cin>>p>>p1;
			move(p,p1);
		}
		std::cin>>str;
	}
	return 0;
}