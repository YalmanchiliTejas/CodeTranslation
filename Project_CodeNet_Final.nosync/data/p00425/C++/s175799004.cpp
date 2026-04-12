#include <stdio.h>

using namespace std;

class Dice{
public:
	void init(){
		setNumber(1,2,3,4,5,6);
	}

	int roll(char dst){
		switch(dst){
		case 'E':
			setNumber(number[3],number[1],number[0],number[5],number[4],number[2]);
			return number[0];
		case 'N':
			setNumber(number[1],number[5],number[2],number[3],number[0],number[4]);
			return number[0];
		case 'S':
			setNumber(number[4],number[0],number[2],number[3],number[5],number[1]);
			return number[0];
		case 'W':
			setNumber(number[2],number[1],number[5],number[0],number[4],number[3]);
			return number[0];
		case 'R':
			setNumber(number[0],number[2],number[4],number[1],number[3],number[5]);
			return number[0];
		case 'L':
			setNumber(number[0],number[3],number[1],number[4],number[2],number[5]);
			return number[0];
		}
		return -1;//must not reach here
	}

private:
	int number[6];

	void setNumber(int n0,int n1,int n2,int n3,int n4,int n5){
		number[0] = n0;
		number[1] = n1;
		number[2] = n2;
		number[3] = n3;
		number[4] = n4;
		number[5] = n5;
	}

};


int main(){
	int n,sum;
	char buf[7];
	Dice dice;
	scanf("%d",&n);

	while(n != 0){
		dice.init();
		sum=1;
		for(int i=0;i<n;i++){
			scanf("%s",buf);
			sum += dice.roll(buf[0]);
		}
		printf("%d\n",sum);
		scanf("%d",&n);
	}

    return 0;
}