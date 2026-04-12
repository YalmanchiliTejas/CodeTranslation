#include <stdio.h>
#include <string.h>

int main (){
	char s;
	scanf ("%c",&s);
	if(s=='a'||s=='i'||s=='u'||s=='e'||s=='o'){
		printf ("vowel\n");
	}else printf ("consonant\n");
}