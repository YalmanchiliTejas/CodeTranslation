#include<bits/stdc++.h>
using namespace std;

main(){
	while(true){
		int maxI=0, maxV=0;
		
		for(int i=0; i<5; ++i){
			int a,b,v;
			cin >> a >> b;
			if(a==0 &&b==0){
				return 0;
			}
			v = a+b;
			if( maxV < v ){
				maxI = i;
				maxV = v;
			}
		}
		
		printf("%c %d\n",'A'+maxI,maxV);
	}
}
