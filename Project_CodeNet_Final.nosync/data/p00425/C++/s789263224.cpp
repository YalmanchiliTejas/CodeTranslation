#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void swap(int &a,int &b){int tem;tem=a,a=b,b=tem;}

class dice {
	public :
	int up,front,right;
	int UP(){return up;}
	int DOWN(){return 7-up;}
	int RIGHT(){return right;}
	int LEFT(){return 7-right;}
	int FRONT(){return front;}
	int BACK(){return 7-front;}
	void South(){ swap(front,up);up=7-up;};
	void North(){ South(),South(),South();};
	void East(){ swap(right,up);up=7-up;};
	void West(){ East(),East(),East();};
	void Right(){swap(front,right),right=7-right;};
	void Left(){Right(),Right(),Right();};
};

int main(void){
	int n;
	map<string,int> list;
	list["North"]=1;
	list["South"]=2;
	list["West"]=3;
	list["East"]=4;
	list["Left"]=5;
	list["Right"]=6;
	while(cin >> n,n){
		int sum=1;
		dice d;
		d.up=1,d.front=2,d.right=3;
		for(int i=0;i<n;i++){
			string S;
			cin >> S;
			int tmp=list[S];
			switch(tmp){
				case 1:
					d.North();
					sum+=d.UP();
					break;
				case 2:
					d.South();
					sum+=d.UP();
					break;
				case 3:
					d.West();
					sum+=d.UP();
					break;
				case 4:
					d.East();
					sum+=d.UP();
					break;	
				case 5:
					d.Left();
					sum+=d.UP();
					break;	
				case 6:
					d.Right();
					sum+=d.UP();
					break;	
				}
		}
	cout << sum << endl;
	}
	return 0; 
}