#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <math.h>
#include <map>
#include <set>
#define sc scanf
#define pr printf
using namespace std;
typedef long long ll;
const int N = 100000+100;
bool ans[N];
char str[N];
bool hander_ans(int n);
bool is_right(int check_index , int rh , int lh);
int main()
{
    int i,j,n;
    while(~sc("%d",&n))
    {
        sc(" %s",str);

        ans[0] = 0 , ans[1] = 0;
        if(hander_ans(n)) continue;

        ans[0] = 0 , ans[1] = 1;
        if(hander_ans(n)) continue;

        ans[0] = 1 , ans[1] = 0;
        if(hander_ans(n)) continue;

        ans[0] = 1 , ans[1] = 1;
        if(hander_ans(n)) continue;

        pr("-1\n");
    }
    return 0;
}
bool is_right(int check_index , int rh , int lh)
{
    if(ans[check_index] == 0)
    {
        if(str[check_index] == 'o' && ans[rh] == ans[lh]) return 1;
        if(str[check_index] == 'x' && ans[rh] != ans[lh]) return 1;
    }
    else
    {
        if(str[check_index] == 'o' && ans[rh] != ans[lh]) return 1;
        if(str[check_index] == 'x' && ans[rh] == ans[lh]) return 1;
    }
    return 0;
}
bool hander_ans(int n)
{
    int i,j;
    for(i=2; i<n; i++)
    {
        if(ans[i-1] == 0)
        {
            if(str[i-1] == 'o')
                ans[i] = ans[i-2];
            else
                ans[i] = !ans[i-2];
        }
        else
        {
            if(str[i-1] == 'o')
                ans[i] = !ans[i-2];
            else
                ans[i] = ans[i-2];
        }
    }
    int flag = 0;
    if(is_right(n-1,0,n-2)) flag++;
    if(is_right(0,1,n-1)) flag++;
    if(flag == 2)
    {
        for(i=0; i<n; i++)
          if(ans[i]) pr("W");
          else pr("S");
         pr("\n");
         return 1;
    }
    return 0;
}
