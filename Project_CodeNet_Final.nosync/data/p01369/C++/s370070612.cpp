#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int func(char ch){
	if(ch == 'q' || ch == 'w' || ch == 'e' || ch == 'r' || ch == 't' || ch == 'a' || ch == 's' || ch == 'd' || ch == 'f' || ch == 'g' ||
			ch == 'z' || ch == 'x' || ch == 'c' || ch == 'v' || ch == 'b'){
		return 1;
	}else{
		return 2;
	}
}


int main(){

	int count;
	char pre,buf[33];

	while(true){
		scanf("%s",buf);
		if(buf[0] == '#')break;

		count = 0;
		pre = buf[0];

		for(int i = 1; buf[i] != '\0'; i++){
			if(func(pre) != func(buf[i]))count++;
			pre = buf[i];
		}

		printf("%d\n",count);
	}
}