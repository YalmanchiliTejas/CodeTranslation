#include <cstdio>
using namespace std;
int x,y,z;
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&x,&y,&z);
	printf("%d\n",(x-z)/(y+z));
	return 0;
}