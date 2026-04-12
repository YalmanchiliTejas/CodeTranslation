#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
 
using namespace std;
typedef long long ll;

int main()
{
	char S[256];
	scanf("%s", S);
	
	int A = 0;
	
	for(int i = 0; i < 3; i++){
		if(S[i] == 'A'){
			A++;
		}
	}
	
	if(A > 0 && A < 3){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}