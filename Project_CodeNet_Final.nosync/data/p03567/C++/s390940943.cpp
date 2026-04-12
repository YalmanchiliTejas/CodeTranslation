#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
void read(int &k){
	k=0; int f=1; char c=getchar();
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while ('0'<=c&&c<='0')k=k*10+c-'0',c=getchar();
	k*=f;
}
int main(){
    char s[100];
    scanf("%s",s); 
    int n=strlen(s);
    for (int i=0;i<n;i++){
    	if (s[i]=='A'&&s[i+1]=='C'){
    		printf("Yes");
    		return 0;
    	}
    }
    printf("No");
	return 0;
}