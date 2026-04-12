#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
	char m[10],st[150],c1[32]={' ','E','P','C','D','I','K','R','F','O','S','T','L',39,',','.','?','A','H','W','X','Y','Z','-','B','G',
	             'J','M','N','Q','U','V'};
	char da1[32][9]={"101","110","111","0101","0001","0111","0110","1000","01001","00101","00110","00111","00100",
		             "000000","000011","010001","000001","100101","010000","000010","10010010","10010011","10010000",
					 "10010001","10011010","10011011","10011000","10011001","10011110","10011111","10011100","10011101"};
    int d[256],i,j,k,a,b,c;
	for (i=0;i<26;i++) d['A'+i]=i;
	d[' ']=26; d['.']=27; d[',']=28; d['-']=29; d[39]=30; d['?']=31;
	while (gets(st)!=NULL) {
		c=0;
		for (i=0;i<strlen(st);i++) for (j=16;j>0;j/=2) {
			m[c++]=((d[st[i]] & j)==0) ? '0' : '1'; m[c]='\0';
			b=0;
			switch(c) {
              case 3: a=0; b=2; break;
			  case 4: a=3; b=7; break;
			  case 5: a=8; b=12; break;
			  case 6: a=13; b=19; break;
			  case 8: a=20; b=31; break;
			}
			if (b>0) for(k=a;k<=b;k++) if (strcmp(m,da1[k])==0) { cout << c1[k] ; c=0;}
		}
		cout << endl;
	}
	return 0;
}