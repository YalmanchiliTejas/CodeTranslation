#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,cnt;
	char s[3];
	scanf("%s",s);
	for(i=0;i<3;i++){
		if(s[i]=='B'){
			cnt++;
		}
	}
	if(cnt==0||cnt==3) printf("No\n");
	else printf("Yes\n");
	return 0;
}