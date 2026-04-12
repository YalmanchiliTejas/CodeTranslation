#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w,cnt=0;
	cin>>h>>w;
	char c;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>c;
			if(c=='#'){
				cnt++;
			}
		}
	}
	if(h+w-1==cnt){
		cout<<"Possible";
	}else{
		cout<<"Impossible";
	}
	return 0;
}