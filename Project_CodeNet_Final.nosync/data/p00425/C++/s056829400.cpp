#include <iostream>

using namespace std;

void rotate(int d[], int id2, int id4){
	int tmp = *d;
	d[0] = d[id2];
	d[id2] = d[5];
	d[5] = d[id4];
	d[id4] = tmp;
}

int main(){
	int n;
	while(cin >> n, n){
		int d[]={1,2,3,4,5,6},dir,rot=0,res=1;
		for(int i=0;i<n;i++){
			char s[9]; cin >> s;
			if(*s%6-4){
				dir=(*s-78?*s%5-1:0)+rot&3;
				dir=dir+1+(1-dir%2*2)*(dir/2);
				rotate(d, dir, 5-dir);
//				if(dir == 0) rotate(d, 1, 4);
//				if(dir == 1) rotate(d, 2, 3);
//				if(dir == 2) rotate(d, 4, 1);
//				if(dir == 3) rotate(d, 3, 2);
			} else rot+=*s+3;
			res+=*d;
		}
		cout << res << endl;
	}
}