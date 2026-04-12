#include<iostream>
using namespace std;

unsigned int n,ans,up,lef,rig;
char action[10];

void north(){
	int tmp = up;
	up = lef;
	lef = 7-tmp;
}

void south(){
	int tmp = lef;
	lef = up;
	up = 7-tmp;
}

void east(){
	int tmp = rig;
	rig = up;
	up = 7-tmp;
}

void west(){
	int tmp = up;
	up = rig;
	rig = 7-tmp;
}

void right(){
	int tmp = lef;
	lef = rig;
	rig = 7-tmp;
}

void left(){
	int tmp = rig;
	rig = lef;
	lef = 7-tmp;
}


void solve(const char a){
	switch(a){
	case 'N':
		north();
		break;
	case 'S':
		south();
		break;
	case 'E':
		east();
		break;
	case 'W':
		west();
		break;
	case 'R':
		right();
		break;
	case 'L':
		left();
		break;
	}
}

void input(){
	for(int i=0; i<n; i++){
		cin >> action;
		solve(action[0]);
		ans += up;
	}
}

int main(){
	while(true){
		cin >> n;
		if(n==0)
			return 0;
		up = 1;
		lef = 2;
		rig = 3;
		ans = 1;
		input();
		cout << ans << endl;
	}
}