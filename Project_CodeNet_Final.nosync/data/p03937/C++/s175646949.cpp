#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;




int main(void)
{
	int H, W;
	int a[8][8];
	char s[8];
	cin>>H;
	cin>>W;
	int i, j;
	char cnt = 0;
	for( i = 0; i < H; i++ ) {
		cin>>s;
		for( j = 0; j < W; j++ ) {
			a[i][j] = s[j];
			if (a[i][j] == '#') cnt++;
		}
	}
	if( (H + W - 1) == cnt ){
		cout<<"Possible"<<endl;
	} else {
		cout<<"Impossible"<<endl;
	}
	
	return 0;
	
}