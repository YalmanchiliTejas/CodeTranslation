#include <iostream>

using namespace std;

void rotate(int d[], int id1, int id2, int id3, int id4){
	int tmp = d[id1];
	d[id1] = d[id2];
	d[id2] = d[id3];
	d[id3] = d[id4];
	d[id4] = tmp;
}

int main(){
	int n;
	while(cin >> n, n){
		int d[6]={1,2,3,4,5,6};
		int dir, rot=0, res = 1;
		for(int i=0;i<n;i++){
			char s[9]; cin >> s;
			if(s[0]=='L') rot+=3;
			else if(s[0]=='R') rot++;
			else {
				if(s[0]=='N') dir = 0;
				if(s[0]=='W') dir = 1;
				if(s[0]=='S') dir = 2;
				if(s[0]=='E') dir = 3;
				dir = (dir+rot)%4;
				if(dir == 0) rotate(d, 0, 1, 5, 4);
				if(dir == 1) rotate(d, 0, 2, 5, 3);
				if(dir == 2) rotate(d, 0, 4, 5, 1);
				if(dir == 3) rotate(d, 0, 3, 5, 2);
			}
			res += d[0];
		}
		cout << res << endl;
	}
}