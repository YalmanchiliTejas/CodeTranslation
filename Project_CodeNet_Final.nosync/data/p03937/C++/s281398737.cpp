#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int h,w,count=0;
	cin>>h>>w;
	char c[8][8];
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin>>c[i][j];
			if(c[i][j]=='#')
				count++;
		}
	}

	if(count==h+w-1)
		cout<<"Possible"<<endl;
	else
		cout<<"Impossible"<<endl;

}