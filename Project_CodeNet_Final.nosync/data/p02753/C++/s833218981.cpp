#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
char s[5]; 
int main(){
	scanf("%s",s+1);
	if(s[1]==s[2]&&s[2]==s[3]){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}
