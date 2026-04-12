#include<bits/stdc++.h>
using namespace std;
char x[1000];
int main(){
	scanf(" %s", x);
	for(int i = 0; x[i] && x[i+1]; i ++ ){
		if ( x[i] == 'A' && x[i+1] == 'C' ){ puts("Yes"); return 0;}
	}
	puts("No");
	return 0;
}