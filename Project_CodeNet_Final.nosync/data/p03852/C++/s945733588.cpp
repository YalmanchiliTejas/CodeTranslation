#include<cstdio>
using namespace std;
char ch;
int main(){
	ch=getchar();
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')puts("vowel");
	else puts("consonant");
	return 0;
}