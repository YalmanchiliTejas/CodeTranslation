#include<iostream>
#include<string>
using namespace std;

class Dice{
public:
	int top,front,r;
	Dice():top(1),front(2),r(3){}
	void north(){
		int a=top;
		top=front;
		front=7-a;
	}
	void east(){
		int a=top;
		top=7-r;
		r=a;
	}
	void west(){
		int a=top;
		top=r;
		r=7-a;
	}
	void south(){
		int a=top;
		top=7-front;
		front=a;
	}
	void right(){
		int a=front;
		front=r;
		r=7-a;
	}
	void left(){
		int a=front;
		front=7-r;
		r=a;
	}
};
int main(){
	int n;
	string op;
	Dice dice;
	while(cin>>n&&n){
		int ans=1;
		dice = Dice();
		while(n--){
			cin>>op;
			if(op=="North")dice.north();
			else if(op=="East")dice.east();
			else if(op=="West")dice.west();
			else if(op=="South")dice.south();
			else if(op=="Right")dice.right();
			else dice.left();
			ans += dice.top;
		}
		cout<<ans<<endl;
	}
	return 0;
}