#include <iostream>
using namespace std;

int h,w;
char a[8][8];
string ans;

void input(){
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>a[i][j];
		}
	}
}
string solve(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<h;k++){
				for(int l=0;l<w;l++){
					if(a[i][j]=='#'&&a[k][l]=='#'&&i<k&&j>l){
						return "Impossible";
					}
				}
			}
		}
	}
	return "Possible";
}

int main() {
	input();
	ans=solve();
	cout<<ans<<endl;
}