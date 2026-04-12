#include "bits/stdc++.h"
using namespace std;

int h,w;
char a;
bool x[101], y[101];
map<pair<int,int>, char> arr;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>h>>w;
	memset(x, true, h+1);
	memset(y, true, w+1);

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>a;
			arr[make_pair(i,j)]=a;
			if(a=='#'){
				x[i]=false;
				y[j]=false;
			}
		}
	}

	for(int i=1;i<=w;i++){
		if(y[i]){
			for(int j=1;j<=h;j++){
				arr[make_pair(j,i)]='x';
			}
		}
	}

	for(int i=1;i<=h;i++){
		if(x[i]){
			for(int j=1;j<=w;j++){
				arr[make_pair(i,j)]='x';
			}
		}
	}

	bool enter=false;
	for(int i=1;i<=h;i++){
		enter=false;
		for(int j=1;j<=w;j++){
			if(arr[make_pair(i,j)]!='x'){
				cout<<arr[make_pair(i,j)];
				enter=true;
			}
		}
		if(enter)
			cout<<endl;
	}
	return 0;
}