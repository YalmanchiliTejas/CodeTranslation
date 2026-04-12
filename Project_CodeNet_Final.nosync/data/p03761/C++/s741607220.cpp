#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

char s[50][50];
int n;
int cnt[50][50];
int h[50];
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n;i++){
		scanf("%s", &s[i]);
	    int len = strlen(s[i]);
	    for(int j = 0; j < len; j++){
	 	   cnt[s[i][j] - 96][i]++;
	 	   if(i == 1)
	 	   h[s[i][j] - 96]++;
		}
		for(int k = 1; k <= 26; k++){
		   h[k] = min(h[k], cnt[k][i]);
	    }
	}
	int ok = 0;
	 for(int i = 1 ; i <= 26; i++){
	 	 if(h[i] != 0){
	 	 	 for(int j = 1; j <= h[i]; j++){
	 	 	 	 printf("%c",i + 96);
			 }
		 }
		 else ok++;
		 if(ok == 26)
		 	 printf("                                                                                                         ");
	 }
	 printf("\n");
	 return 0;
	}




