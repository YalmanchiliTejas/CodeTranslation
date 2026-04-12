#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>

typedef long long ll;
using namespace std;

int main(){
	char c[101][101],d[101][101],e[101][101];
	int h,w,a[200],b[200],o=0,ans=0;
	for(int i=0;i<101;i++){
		a[i]=0;
		b[i]=0;
	}

	cin >> h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> c[i][j];
			if(c[i][j]=='#'){
				a[i]++;
			}
		}
		if(a[i]!=0){
			for(int u=0;u<w;u++){
				d[o][u]=c[i][u];
			}
			o++;
		}
	}
	h=o;
	for (int i=0;i<w;i++)
	{
		for(int j=0;j<o;j++){
			if(d[j][i]=='#'){
				b[i]++;
			}
		}
		if(b[i]!=0){
			for(int u=0;u<h;u++){
				e[u][ans]=d[u][i];
			}
			ans++;
		}
	}
	w=ans;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << e[i][j];
		}
		cout << endl;
	}
  return 0;
}

