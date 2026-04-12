#include <cstdio>
using namespace std;

int max( int a, int b ){
  if ( a > b ) return a;
  return b;
}

int n,h;
int Max = 0, total = 0;

int main(){
  	
  	scanf("%d",&n);
  	for ( int i = 0; i < n; i++ ){
    	scanf("%d",&h);
      	if ( Max <= h ) total++;
      	Max = max( Max, h );
    }
  	printf("%d\n",total);
	return 0;
}