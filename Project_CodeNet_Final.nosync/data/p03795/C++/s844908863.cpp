#include<bits/stdc++.h>
using namespace std;
int main(){
	int N=0,x=0,y=0;
	int price=800;
	scanf("%i",&N);
	if(N>=1 && N<=100){
		 x=price*N;
		 if(N>=15){
		 	for(int i=15;i<=N;i+=15)
		 		y+=200;
		 }
	}
	printf("%i",x-y);
}