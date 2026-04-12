#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int H,W,i,j;
	string str;
	cin>>H>>W;
	vector<string> grid;
	vector<bool> hflag,wflag;
	for(i=0;i<H;i++){
		cin>>str;
		grid.push_back(str);
	}
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(grid.at(i).at(j)=='#'){
				break;
			}
		}
		if(j==W){
			//cout<<"a";
			hflag.push_back(0);
		}else{
			//cout<<"b";
			hflag.push_back(1);
		}
	}
	for(i=0;i<W;i++){
		for(j=0;j<H;j++){
			if(grid.at(j).at(i)=='#'){
				break;
			}
		}
		if(j==H){
			//cout<<"c";
			wflag.push_back(0);
		}else{
			//cout<<"d";
			wflag.push_back(1);
		}
	}
	for(i=0;i<H;i++){
		if(hflag.at(i)){
			for(j=0;j<W;j++){
				if(wflag.at(j)){
					cout<<grid.at(i).at(j);
				}
			}
			cout<<endl;
		}
	}
}
