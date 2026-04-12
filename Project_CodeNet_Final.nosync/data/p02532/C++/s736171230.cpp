#include<iostream>
#include<string>
#include<vector>
int main(){
	int m=0,mountain;
	std::cin>>mountain;
	std::vector<int> n(1000);
	std::vector<char> remove(1000);
	std::vector<std::vector<int> > block(mountain+1,std::vector<int>(1000));
	std::string str;
	while(std::cin>>str,str!="quit"){
		if(str=="push"){
			int x;
			char color;
			std::cin>>x>>color;
			block[x][n[x]]=color-'a';
			n[x]++;
		}
		else if(str=="pop"){
			int x;
			std::cin>>x;
			n[x]--;
			remove[m]=block[x][n[x]]+'a';
			m++;
		}
		else if(str=="move"){
			int x,y;
			std::cin>>x>>y;
			n[x]--;
			block[y][n[y]]=block[x][n[x]];
			n[y]++;
		}
	}
	for(int i=0;i<m;i++){
		std::cout<<remove[i]<<std::endl;
	}
}