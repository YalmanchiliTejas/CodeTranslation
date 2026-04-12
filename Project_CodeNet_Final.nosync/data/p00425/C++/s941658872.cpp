#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

class Dice{
public:
	vector<int> dice;
	Dice(){
		dice.resize(6);
		rep(i,6) dice[i] = (i+1);
	}
	void left(){
		int to[] = {1,3,5,2,4,6};
		vector<int> tmp = dice;
		rep(i,6)tmp[i] = dice[to[i]-1];
		dice = tmp;
	}
	void west(){
		int to[] = {3,2,6,1,5,4};
		vector<int> tmp = dice;
		rep(i,6)tmp[i] = dice[to[i]-1];
		dice = tmp;
	}
	void north(){
		int to[] = {2,6,3,4,1,5};
		vector<int> tmp = dice;
		rep(i,6)tmp[i] = dice[to[i]-1];
		dice = tmp;
	}
};

int main(){
	int n;
	while(cin >> n,n){
		int ans = 0;
		Dice d;
		rep(i,n){
			string str;
			cin >> str;
			switch(str[0]){
			case 'N':
				d.north();
				break;
			case 'E':
				rep(j,3)d.west();
				break;
			case 'W':
				d.west();
				break;
			case 'S':
				rep(j,3)d.north();
				break;
			case 'R':
				d.left();
				break;
			case 'L':
				rep(j,3)d.left();
				break;
			}
			ans += d.dice[0];
		}
		cout << ans+1 << endl;
	}
}