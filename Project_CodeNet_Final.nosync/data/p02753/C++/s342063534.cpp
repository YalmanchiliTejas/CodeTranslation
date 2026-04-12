#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
	char s[5];
	scanf("%s",s);
	if(s[0]==s[1]&&s[1]==s[2]){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	return 0;
}