#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 55
using namespace std;
bool cmp(char a[],char b[]){
	
	return strcmp(a,b)>0?0:1; 
	
}
int main(){
	int n;
	int str[55][30]={0};
	scanf("%d\n",&n);
	char tmp[55];
	for(int i=0;i<n;i++){
		int len=0;
		char ch;
		ch=getchar();
		while(ch!=char(10)){
			str[i][ch-'a'+1]++;
			ch=getchar();
		}
	}
	int len=0;
	for(int j=1;j<=26;j++){
		int mx=55;
		for(int i=0;i<n;i++){
			mx=min(mx,str[i][j]);
			if(mx==0){
				break;
			}
		}
		while(mx--){
			printf("%c",j+'a'-1);
		}
	}
	printf("\n");
	return 0;
} 