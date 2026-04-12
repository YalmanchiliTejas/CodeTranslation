#include<bits/stdc++.h>
using namespace std;
bool f[110][110];
bool book[110][110];
char ch;
int main() {
	memset(book,true,sizeof(book));
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++) 
		for(int j=0;j<w;j++) {
			cin>>ch;
			if(ch=='#')
				f[i][j] = true;
			if(ch=='.')
				f[i][j] = false; 
		}
	bool tmp;
	for(int i=0;i<h;i++) {
		tmp = true;
		for(int j=0;j<w;j++) {
			if(f[i][j]==true) {
				tmp = false;
				break;
			}
		}
		if(tmp==true)
			for(int j=0;j<w;j++)
				book[i][j] = false;
	}
	for(int i=0;i<w;i++) {
		tmp = true;
		for(int j=0;j<h;j++) {
			if(f[j][i]==true) {
				tmp = false;
				break;
			}
		}
		if(tmp==true)
			for(int j=0;j<h;j++) {
				book[j][i] = false;
			}
	}
	for(int i=0;i<h;i++) {
		tmp = false;
		for(int j=0;j<w;j++) {
			if(book[i][j]) {
				tmp = true;
				if(f[i][j]==true) cout<<'#';
				else cout<<'.';
			}
		}
		if(tmp)
			cout<<'\n';
	}
	return 0;
} 