#include <bits/stdc++.h>
using namespace std;
char str[10];
bool jay1,jay2;
int main(){
	scanf("%s",&str);
	for (register int i=0; i<3; ++i) 
	{
		if (str[i]=='A') jay1=true;
		if (str[i]=='B') jay2=true;
	}	
	if (!jay1 || !jay2) puts("No");
	else puts("Yes"); 
return 0;
}
