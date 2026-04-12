#include <iostream>
#include <string>
using namespace std;

class Dice{
private:
	int top,bottom,right,left,front,back;
	
	void North();
	void South();
	void East();
	void West();
	void Right();
	void Left();
	
public:
	Dice(){
		top = 1;
		bottom = 6;
		front = 5;
		back = 2;
		right = 3;
		left = 4;
	}
	
	void Turn(string com){
		if(com == "North")North();
		else if(com == "South")South();
		else if(com == "East")East();
		else if(com == "West")West();
		else if(com == "Right")Right();
		else if(com == "Left")Left();
	}
	
	int GetTop(){
		return top;
	}
	
};

void Dice::North(){
	int temp = top;
	top = back;
	back = bottom;
	bottom = front;
	front = temp;
}

void Dice::South(){
	int temp = top;
	top = front;
	front = bottom;
	bottom = back;
	back = temp;
}

void Dice::East(){
	int temp = top;
	top = left;
	left = bottom;
	bottom = right;
	right = temp;
}

void Dice::West(){
	int temp = top;
	top = right;
	right = bottom;
	bottom = left;
	left = temp;
}

void Dice::Right(){
	int temp = back;
	back = right;
	right = front;
	front = left;
	left = temp;
}

void Dice::Left(){
	int temp = back;
	back = left;
	left = front;
	front = right;
	right = temp;
}

int main() {
	
	int n,sum;
	string command;
	
	while(cin>>n,n){
		Dice dice;
		sum = 0;
		for(int i=0;i<n;++i){
			sum += dice.GetTop();
			cin>>command;
			dice.Turn(command);
		}
		sum += dice.GetTop();
		cout<<sum<<endl;
	}
	return 0;
}