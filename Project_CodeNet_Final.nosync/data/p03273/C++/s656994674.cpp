#include<cstdio>
#include<iostream>
using namespace std;
char a[105][105];
int r[105],c[105];
int main() {
	//freopen("in.txt","r",stdin);
	int h,w;
	cin>>h>>w;
	int i,j;
	for(i=1; i<=h; i++) {
		for(j=1; j<=w; j++) {
			cin>>a[i][j];
		}
	}
	int t;
	for(i=1; i<=h; i++) {
		t=0;
		for(j=1; j<=w; j++) {
			if(a[i][j]=='.')
				t++;
		}
		if(t==w) r[i]=1;
	}

	for(i=1; i<=w; i++) {
		t=0;
		for(j=1; j<=h; j++) {
			if(a[j][i]=='.')
				t++;
		}
		if(t==h) c[i]=1;
	}
    int f;
	for(i=1; i<=h; i++) {
		f=0;
		for(j=1; j<=w; j++) {
              if(c[j]||r[i]) continue;
			  cout<<a[i][j]; 
			  f=1;
		}
		if(f)
		  cout<<endl; 
	}
	return 0;
}