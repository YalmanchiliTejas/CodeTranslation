#include <iostream>
#include <algorithm>
struct team{
	std::string name;
	int point;
	int n;
};

bool tsort(const team& a,const team& b){
	if(a.point - b.point){
		return a.point > b.point;
	}
	return a.n < b.n;
}

int main(){
	int n;
	bool f = false;
	while(std::cin>>n,n){
		if(f)std::cout<<std::endl;
		else{f=true;}
		team all[10];
		for(int i = 0;i < n;i++){
			std::string name;
			int w,d,l;
			std::cin>>name>>w>>l>>d;
			team t = {name,w*3+d,i};
			all[i] = t;
		}
		std::sort(all,all+n,tsort);
		for(int i = 0;i < n;i++){
			std::cout<<all[i].name<<","<<all[i].point<<std::endl;
		}
	}
	return 0;
}