#include <iostream>
#include <complex>
#include <string>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
char dice[6][4] = {
	{5,1,2,4}, {1,3,1,0}, {0,2,3,2},
	{2,4,5,1}, {4,0,4,3}, {3,5,0,5}
};
char side[] = {1,2,4,5};
int dice_color[6] = {1, 4, 2, 6, 3, 5};

int getUpper(int a, int b){
	if(a%3 == 0) return dice_color[a+0];
	if(b%3 == 0) return dice_color[b+1];
	for(int i=0;i<4;i++)
		if(a==side[i]&&b==side[(i+1)%4]) return dice_color[2];
	return dice_color[5];
}


int main(){
	int n;
	while(cin >> n, n){
		string s;
		int a = 0, b = 1, c = 0;
		int res = 1;
		for(int i=0;i<n;i++){
			cin >> s;
			int d = -1;
			if(s[0]=='L') c = (c+3)%4; 
			if(s[0]=='R') c = (c+1)%4;
			if(s[0]=='W') d = 1;
			if(s[0]=='N') d = 0;
			if(s[0]=='E') d = 3;
			if(s[0]=='S') d = 2;
			if(d!=-1){
				a = dice[a][(d+c)%4];
				b = dice[b][(d+c)%4];
			}
			res += getUpper(a, b);
		}
		cout << res << endl;
	}
}