#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
#include<set>

const int maxn=1e5+5;

using namespace std;

char s[5];

int main()
{
    scanf("%s",&s);
    if(s[0]==s[1]&&s[0]==s[2])
        printf("No\n");
    else
        printf("Yes\n");
}