#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int n,k;
	char str[10];

	scanf("%d",&n);
	scanf("%s",str);
	scanf("%d",&k);
	k--;

	for(int i=0;i<n;i++){
		if(str[i]!=str[k]){
			str[i]='*';
		}
	}

	printf("%s",str);

	return 0;
}