#include<stdio.h>
#include<string.h>
#include<math.h>
int a,s,d[1001],f,g,h;
char z[21];
int main(void)
{
	int i,j,k;
	while(1){
		scanf("%d %d",&a,&s);
		if(a==0&&s==0) break;
		h=a;
		for(i=1;i<=a;i++) d[i]=i;
		j=0;
		for(i=1;i<=s;i++){
			scanf("%s",z);
			if(h>1){
				f=0;
				j++;
				while(1){
					if(j>a) j=1;
					if(d[j]==0) j++;
					if(j>a) j=1;
					if(d[j]!=0) break;
				}
				if(i%3==0){
					if(i%5!=0){
						f=strcmp(z,"Fizz\0");
						if(f!=0){
							h--;
							d[j]=0;
						}
					}
					else if(i%5==0){
						f=strcmp(z,"FizzBuzz\0");
						if(f!=0){
							h--;
							d[j]=0;
						}
					}
				}
				else if(i%5==0){
					if(i%3!=0){
						f=strcmp(z,"Buzz\0");
						if(f!=0){
							d[j]=0;
							h--;
						}
					}
				}
				else if(i%3!=0&&i%5!=0){
					f=0;
					for(k=0;k<strlen(z);k++){
						f*=10;
						f+=z[k]-'0';
					}
					if(f!=i){
						d[j]=0;
						h--;
					}
				}
			}
		}
		for(i=1;i<=a;i++){
			if(d[i]!=0){
				printf("%d",i);
				h--;
				if(h>0) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}