#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    char s[6];
    while(scanf("%s",s)!=EOF)
    {
        int flag=0;
        for(int i=0;i<strlen(s)-1;i++)
        {
            if(s[i]=='A'&&s[i+1]=='C')
                {
                    printf("Yes\n");
                    flag=1;
                    break;
                }
        }
        if(!flag)
            puts("No");
    }
    return 0;


}
