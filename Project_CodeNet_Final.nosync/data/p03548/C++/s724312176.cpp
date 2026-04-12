#include<bits/stdc++.h>
using namespace std;
int main(){
	int w,x,y,z,n;
	cin>>x>>y>>z;
	w=z;
	n=0;
	while(w<x){
		w+=y+z;
		if(w>x){
			break;
		}
		n++;
	}
	cout<<n<<endl;
}