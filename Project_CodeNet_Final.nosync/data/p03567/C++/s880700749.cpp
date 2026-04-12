#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
using namespace std;
int main()
{
	char c,cc=32;bool flag(false);
	while((c=getchar())!=10){if((!(c-67))&&(!(cc-65))){flag=true;break;}cc=c;}
	puts(((flag)?("Yes"):("No")));
	return 0;
}