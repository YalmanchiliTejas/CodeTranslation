#include <iostream>
#include <complex>
#include <string>

using namespace std;

char dice[6][4] = {
	{5,1,2,4}, {1,3,1,0}, {0,2,3,2},
	{2,4,5,1}, {4,0,4,3}, {3,5,0,5}
};

int main(){
	int n;
	while(cin >> n, n){
		string s;
		int a = 0, b = 1, c = 0, r = 1;
		for(int i=0;i<n;i++){
			cin >> s;
			int d = -1;
			if(s[0]=='L') c+=3; 
			if(s[0]=='R') c++;
			if(s[0]=='W') d = 1;
			if(s[0]=='N') d = 0;
			if(s[0]=='E') d = 3;
			if(s[0]=='S') d = 2;
			if(d!=-1){
				a = dice[a][(d+c)%4];
				b = dice[b][(d+c)%4];
			}
			r += a%3?b%3?(b+6-a)%6<3?2:5:b?3:4:a?6:1;
		}
		cout << r << endl;
	}
}