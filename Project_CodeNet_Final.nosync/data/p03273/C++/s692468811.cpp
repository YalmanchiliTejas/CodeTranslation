#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
//
const int inf=1e9+7;//0x3f
//
char M[100][100];
bool h[100],w[100];
int main(){
	int H,W;
	cin>>H>>W;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>M[i][j];
		}
	}
	for(int i=0;i<H;i++){
		bool f=true;
		for(int j=0;j<W;j++){
			if(M[i][j]=='#'){
				f=false;
				break;
			}
		}
		h[i]=f;
	}
	for(int i=0;i<W;i++){
		bool f=true;
		for(int j=0;j<H;j++){
			if(M[j][i]=='#'){
				f=false;
				break;
			}
		}
		w[i]=f;
	}
	//
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(h[i]||w[j]){
				continue;
			}else{
				cout<<M[i][j];
			}
		}
		if(!h[i]){
			cout<<endl;
		}
	}
	return 0;
}