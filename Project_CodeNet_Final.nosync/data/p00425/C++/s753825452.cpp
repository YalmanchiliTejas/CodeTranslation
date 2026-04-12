#import<cstdio>
int main(){for(int a,c,r,t;r=c=0,~a;r&&printf("%d\n",r+1))for(char d[]="12354",s[9];a=scanf("%s",s),--*s>60;r+=*d&7)*s%3?t=*d,*d=d[a+=*s%5+*s*2+c&3],d[a]=~t,d[++a%4+1]=t:c+=*s;}