#include <stdio.h>
#include <string.h>
#define MAX 25

char ch[MAX], op1[MAX], op2[MAX];
int len, cnt, ont;
int n1[MAX], n2[MAX];

int go1(void){
	int i, j;
	int c=cnt, o=ont;
	for (i=1;i<=o;i++){
		if (op1[i]=='*'){
			n1[i]*=n1[i+1];
			for (j=i+1;j<=c;j++){
				n1[j]=n1[j+1];
			}
			c--;
			for (j=i;j<=o;j++){
				op1[j]=op1[j+1];
			}
			o--;
			i--;
		}
	}
	for (i=1;i<=o;i++){
		if (op1[i]=='+'){
			n1[i]+=n1[i+1];
			for (j=i+1;j<=c;j++){
				n1[j]=n1[j+1];
			}
			c--;
			for (j=i;j<=o;j++){
				op1[j]=op1[j+1];
			}
			o--;
			i--;
		}
	}
	return n1[1];
}

int go2(void){
	int i, j;
	int o=ont, c=cnt;
	for (i=1;i<=o;i++){
		if (op2[i]=='+'){
			n2[i]+=n2[i+1];
		}else if (op2[i]=='*'){
			n2[i]*=n2[i+1];
		}
		for (j=i+1;j<=c;j++){
			n2[j]=n2[j+1];
		}
		c--;
		for (j=i;j<=o;j++){
			op2[j]=op2[j+1];
		}
		o--;
		i--;
	}
	return n2[1];
}

int main(void){
	int i;
	scanf("%s", &ch[1]);
	len=strlen(&ch[1]);
	for (i=1;i<=len;i+=2){
		n1[++cnt]=ch[i]-'0';
		n2[cnt]=n1[cnt];
	}
	for (i=2;i<=len;i+=2){
		op1[++ont]=ch[i];
		op2[ont]=op1[ont];
	}
	int r1, r2;
	r1=go1();
	r2=go2();

	int n;
	scanf("%d", &n);
	if (r1==n && r2==n) printf("U\n");
	else if (r1==n) printf("M\n");
	else if (r2==n) printf("L\n");
	else printf("I\n");
	return false;
}