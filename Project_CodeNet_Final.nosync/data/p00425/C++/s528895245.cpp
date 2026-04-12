#include <iostream>

int top,front,migi;

int north(){
	int bottom=7-top;
	top=front;
	front=bottom;
	return 0;
}
int east(){
	int left=7-migi;
	migi=top;
	top=left;
	return 0;
}
int west(){
	int bottom=7-top;
	top=migi;
	migi=bottom;
	return 0;
}
int south(){
	int back=7-front;
	front=top;
	top=back;
	return 0;
}
int right(){
	int back=7-front;
	front=migi;
	migi=back;
	return 0;
}
int left(){
	int left=7-migi;
	migi=front;
	front=left;
	return 0;
}

int main(){
	int i,n,ans=1;
	char order[10];
	while(1){
		std::cin >> n;
		if(!n) break;
		top=1;front=2;migi=3;
		for(i=0;i<n;i++){
			std::cin >> order;
			if(order[0]=='N') north();
			else if(order[0]=='S') south();
			else if(order[0]=='E') east();
			else if(order[0]=='W') west();
			else if(order[0]=='R') right();
			else left();
			ans+=top;
		}
		std::cout<<ans<<std::endl;ans=1;
	}
}