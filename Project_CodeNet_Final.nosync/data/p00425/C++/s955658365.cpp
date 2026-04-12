#import<cstdio>
int main(){for(int a,c,r,t;r=1,c=3,~a;~-r&&printf("%d\n",r))for(char d[]="12354",s[9];a=scanf("%s",s),*s>60;r+=*d&7)*s%6-4?t=*d,*d=~d[a+=*s%5+*s*2+c&3],d[a]=t,d[++a%4+1]=~t:c+=*s+3;}