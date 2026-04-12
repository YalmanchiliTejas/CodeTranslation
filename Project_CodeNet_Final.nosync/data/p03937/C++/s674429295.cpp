#include<bits/stdc++.h>
using namespace std;

char a[10][10]{};
int b,c;
void f(int d,int e){
	a[d][e]='.';
if(d+1==b&&e+1==c)return;
if(a[d+1][e]=='#'&&d+1<b){f(d+1,e);}
else if(a[d][e+1]=='#'&&e+1<c)f(d,e+1);
return;
}
signed main(){
cin>>b>>c;
for(int d=0;d<b;d++){
	for(int e=0;e<c;e++)cin>>a[d][e];
}
bool s=false;
f(0,0);
for(int x=0;x<b;x++){
	for(int y=0;y<c;y++)if(a[x][y]=='#')s=true;
}
if(s)puts("Impossible");
else puts("Possible");
}