#include<string>
#include<iostream>
class Cube{	
public:
	long long plane[6];
	void North(){
		int buf = plane[1-1];
		plane[1-1] = plane[6-1];
		plane[6-1] = plane[3-1];
		plane[3-1] = plane[5-1];
		plane[5-1] = buf;
	}
	void East(){
		int buf = plane[2-1];
		plane[2-1] = plane[5-1];
		plane[5-1] = plane[4-1];
		plane[4-1] = plane[6-1];
		plane[6-1] = buf;
	}
	void West(){
		int buf = plane[2-1];
		plane[2-1] = plane[6-1];
		plane[6-1] = plane[4-1];
		plane[4-1] = plane[5-1];
		plane[5-1] = buf;
	}
	void South(){
		int buf = plane[1-1];
		plane[1-1] = plane[5-1];
		plane[5-1] = plane[3-1];
		plane[3-1] = plane[6-1];
		plane[6-1] = buf;
	}
	void Right(){
		int buf = plane[1-1];
		plane[1-1] = plane[2-1];
		plane[2-1] = plane[3-1];
		plane[3-1] = plane[4-1];
		plane[4-1] = buf;
	}
	void Left(){
		int buf = plane[1-1];
		plane[1-1] = plane[4-1];
		plane[4-1] = plane[3-1];
		plane[3-1] = plane[2-1];
		plane[2-1] = buf;
	}
};
using namespace std;
int main(){
	Cube dice;
	int n,num;
	string trend;
	while(1){

		dice.plane[1-1]=2;
		dice.plane[2-1]=3;
		dice.plane[3-1]=5;
		dice.plane[4-1]=4;
		dice.plane[5-1]=1;
		dice.plane[6-1]=6;

		num=0;
		num+=dice.plane[4];
		
		cin >> n;
		
		if(n==0)break;
		
		for(int i=0;i<n;i++){
			cin >> trend;
		
			if(trend=="North"){
				dice.North();
			}else if(trend=="East"){
				dice.East();
			}else if(trend=="West"){
				dice.West();
			}else if(trend=="South"){
				dice.South();
			}else if(trend=="Right"){
				dice.Right();
			}else if(trend=="Left"){
				dice.Left();
			}
			num+=dice.plane[4];
		}
		cout << num << endl;
	}
	cin >> n;
}