#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(void){
	char str[5] = "\0";
	bool frag = false;
	scanf("%s", str);
	
	for (int i = 0; i < 4; i++){
		if (str[i] == 'A' && str[i + 1] == 'C')
			frag = true;
	}

	if (frag)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}