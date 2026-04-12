#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
	int i,j,k=0,l=0,h,w;
	cin>>h>>w;
	string s[h];
	vector<int> x,y;
	for(i=0;i<h;i++)cin>>s[i];
	for(i=0;i<h;i++){
		int f=1;
		for(j=0;j<w;j++){
			if(s[i][j]=='#')f=0;
		}
		if(f)x.push_back(i);
	}
	for(j=0;j<w;j++){
		int f=1;
		for(i=0;i<h;i++){
			if(s[i][j]=='#')f=0;
		}
		if(f)y.push_back(j);
	}
	x.push_back(100);
	y.push_back(100);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(x[k]!=i&&y[l]!=j)cout<<s[i][j];
			if(y[l]==j&&l<y.size()-1)l++;
		}
		if(x[k]==i&&k<x.size()-1)k++;
		else cout<<endl;
		l=0;
	}
	return 0;
}