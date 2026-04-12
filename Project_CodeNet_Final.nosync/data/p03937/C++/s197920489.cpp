#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <random>
#include <cstdio>

using namespace std;

int main(){
	int H,W;
	cin>>H>>W;
	vector<string> A(H);
	string a;
	int NbN=0;
	for(int i=0;i<H;i++){
		cin>>A[i];
		for(int j=0;j<W;j++){
			if(A[i][j]=='#') NbN++;
		}
	}
	int x=0,y=0;
	int cnt=1;
	if(A[y][x+1]=='#' && A[y+1][x]=='#'){
		cout<<"Impossible"<<endl;
		return 0;
	}

	if(A[y][x+1]=='#') x++;
	else if(A[y+1][x]=='#') y++;
	//cout<<y<<" "<<x<<endl;
	cnt++;
	while(x<W-1 || y<H-1 ){
		bool x_W=true;
		bool y_H=true;
		if(x>W-2){
			x_W=false;
		}
		if(y>H-2){
			y_H=false;
		}
		bool right=false;
		bool bottom=false;
		if(x_W && A[y][x+1]=='#'){
			cnt++;
			x++;
		}else if(y_H && A[y+1][x]=='#'){
		
			cnt++;
			y++;
		}else{
			cout<<"Impossible"<<endl;
			return 0;
		}
		//cout<<y<<" "<<x<<" "<<cnt<<endl;
	}
	//cout<<NbN<<" "<<cnt<<endl;
	if(cnt==NbN){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;	
}
