//gcc listsirkuler.c map.c player.c mesinkata.c mesinkar.c matriks.c pcolor.c point.c queue.c unit.c main.c -o main
#include <bits/stdc++.h>
#define Semangat using
#define World namespace
#define Final std;
#define WF {ios_base::sync_with_stdio(0);cin.tie(0);}
 
Semangat World Final

long x,y,z,i;

int main(){
	WF
	cin>>x>>y>>z;
	for(i=0; i<=100000; i++){
		if(y*i+z*(i+1)>x)
			break;
	}
	cout<<i-1<<"\n";
	return 0;
}