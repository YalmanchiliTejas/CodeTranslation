#include<iostream>
using namespace std;
int main(){
	int x,y,n;
	scanf("%d",&x);
    n=x*800;
    for(int i=x;i>=15;i-=15){
    	y++;
	}
	y=y*200;
	cout<<n-y;
}
