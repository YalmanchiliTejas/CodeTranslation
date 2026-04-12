/*
 * 16-11-12_AGC007_A.cpp
 *
 *  Created on: 2016/11/12
 *      Author: ryoma
 */
#include<iostream>

using namespace std;

int H,W;
char a[10][10];
int cnt;
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++){
			cin >> a[i][j];
			if(a[i][j]=='#')
				cnt++;
		}
	cout<<(cnt==H+W-1? "Possible":"Impossible")<<endl;
	return 0;
}



