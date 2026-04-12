#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;

int main(){
	int H,W;
	cin>>H>>W;
	int sp=0;
	rep(i,H*W){
		char x;
		cin>>x;
		if(x=='#')sp++;
	}
	if(sp==H+W-1)cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}
