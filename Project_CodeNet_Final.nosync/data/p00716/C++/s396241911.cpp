#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <math.h>
using namespace std;

int main() {
	
	int m,n,gf,g,y,sc,c,in,max;
	double r;
	cin>>m;
	
	for(int i=0;i<m;i++){
		max=0;
		cin>>gf>>y>>n;
		
		for(int j=0;j<n;j++){
			in=0;
			cin>>sc>>r>>c;
			if(sc==0){
				g=gf;
				for(int k=0;k<y;k++){
					in+=g*r;
					g-=c;
				}
				g+=in;
			}
			else {
				g=gf;
				for(int k=0;k<y;k++){
					g=g*(1+r)-c;
				}
			}
			if(g>max)max=g;
		}
		cout<<max<<endl;
	}
	return 0;
}