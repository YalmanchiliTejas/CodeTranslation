#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct player { int to,fr,f; }; 
player p[1000];

int main() {
  int i,n,m,k,pn;
  char c[10001][9],a[256];
  for (i=1;i<10001;i++) {
	  if ((i % 3)==0 && (i % 5)==0) sprintf(c[i],"%s","FizzBuzz"); else
	  if ((i % 3)==0) sprintf(c[i],"%s","Fizz"); else
	  if ((i % 5)==0) sprintf(c[i],"%s","Buzz"); else
	  sprintf(c[i],"%d",i);
	  }
  while(cin >> m >> n && m>0) {
	  for (i=0;i<m;i++) { p[i].fr=(i+m-1) % m ; p[i].to=(i+1) % m; p[i].f=0;}
	  k=m;
	  for (pn=0,i=1;i<=n;i++) {
		  cin >> a;
		  if (k==1) continue;
		  if (strcmp(a,c[i])!=0) {p[pn].f=1; p[p[pn].fr].to=p[pn].to; p[p[pn].to].fr=p[pn].fr; k--;}
		  pn=p[pn].to;
		  }
	  k=0;	  
	  for (i=0;i<m;i++) if (p[i].f==0) { if (k==1) cout << ' '; 
		  cout << i+1; k=1; }
	  cout << endl;
  }
  return 0;
}