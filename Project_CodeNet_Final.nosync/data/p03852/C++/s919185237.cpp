#include<cstdio>

char c,a[5]={'a','e','i','o','u'};

int main(void){
	register int i;
	c=getchar();
	for(i=0;i<5;++i)
		if(c==a[i])
			return puts("vowel"),0;
	puts("consonant");
	return 0;
}