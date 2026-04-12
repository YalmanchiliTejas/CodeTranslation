#include<stdio.h>

 int main(){
 	char name[5];
 	scanf("%s",&name);
 	if(name[0]==name[1] && name[1]!=name[2] && name[0]!=name[2]){
 		printf ("Yes");
	 }
	 else if (name[1]==name[2] && name[0]!=name[1] && name[0]!=name[2] ){
	 	printf("Yes");
	 }
	 else if (name[0]==name[2] && name[1]!=name[2] && name[0]!=name[1]){
	 	printf("Yes");
	 }
 	else {
 		printf("No");
	 }
 	
 	return 0;
 }