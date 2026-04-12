#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

bool a[101][101];
bool H[101],W[101];
int main() {
	ll h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			char b;
			cin>>b;
			if(b=='#'){
				a[i][j]=1;
			}
		}
	}
	for(int i=0;i<h;i++){
		bool flag=true;
		for(int j=0;j<w;j++){
			if(a[i][j]==1){
				flag=false;
				break;
			}
		}
		if(flag){
			H[i]=true;
		}
	}
	for(int i=0;i<w;i++){
		bool flag=true;
		for(int j=0;j<h;j++){
			if(a[j][i]==1){
				flag=false;
				break;
			}
		}
		if(flag){
			W[i]=true;
		}
	}
	for(int i=0;i<h;i++){
		if(H[i]){
			continue;
		}
		for(int j=0;j<w;j++){
			if(W[j]){
				continue;
			}
			if(a[i][j]==1){
				cout << "#";
			}
			else{
				cout << ".";
			}
		}
		cout << endl;
	}
	// your code goes here
	return 0;
}