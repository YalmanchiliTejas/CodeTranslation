#include <bits/stdc++.h>
using namespace std;

int main() {
	char s;
	bool a = false;
	bool b = false;
	
	for(int i=0; i<3; ++i){
		scanf("%c", &s);
		
		if(s == 'A')
			a = true;
		else if(s == 'B')
			b = true;
	}	
	
	if(a && b)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}
