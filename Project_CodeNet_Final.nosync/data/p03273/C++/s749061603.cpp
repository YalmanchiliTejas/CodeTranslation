#include "bits/stdc++.h"
using namespace std;
int main(){
	int h, w; cin>>h>>w;
	vector<string> m(110);
	bool erasex[110]={}, erasey[110]={};
	for (int i=0; i<h; ++i){
		cin>>m[i];
		if (m[i].find('#')==string::npos)erasey[i]=1;//行iに'#'が一つもなければ、消す列にします。
	}
	bool tmp;
	for (int j=0; j<w; ++j){
		tmp=1;
		for (int i = 0; i<h; ++i)if (m[i][j]=='#')goto L_erase;
		erasex[j]=1;//列jに'#'が一つもなければ、消す列にします。
	L_erase:;
	}

	for (int i=0; i<h; ++i)if (!erasey[i]){
		for (int j=0; j<w; ++j){
			if (!erasex[j])cout<<m[i][j];
		}
		cout<<endl;
	}
}