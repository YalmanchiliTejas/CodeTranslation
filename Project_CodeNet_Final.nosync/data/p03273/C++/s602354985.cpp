#include <iostream>
#include <algorithm>
#include <string>
#include <typeinfo>
#include <cmath>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define ii pair<int,int>
#define MAX 1000000007
using namespace std;

int main(void){
	int h,w;
	cin>>h>>w;
	char a[h][w];
	rep(i,h)rep(j,w)cin>>a[i][j];

	bool h_flag[h],w_flag[w];
	rep(i,h)h_flag[i]=true;
	rep(i,w)w_flag[i]=true;
	rep(i,h){
		rep(j,w){
			if(a[i][j]=='#'){
				h_flag[i]=false;
				w_flag[j]=false;
			}
		}
	}

	rep(i,h){
		rep(j,w){
			if((!h_flag[i]) && (!w_flag[j]))cout<<a[i][j];
		}
		if(!h_flag[i])cout<<endl;
	}

	return 0;
}
