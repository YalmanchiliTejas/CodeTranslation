#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
bool A,B;
int main()
{
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	if(a=='A' || b=='A' || c=='A') A=1;
	if(a=='B' || b=='B' || c=='B') B=1;
	if(A==1 && B==1)
	{
		printf("Yes");
		return 0;
	}
	else printf("No");
	return 0;
	
}