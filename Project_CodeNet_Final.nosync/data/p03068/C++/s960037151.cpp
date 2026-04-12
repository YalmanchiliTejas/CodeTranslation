#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
using namespace std;
char s[12];
int main()
{
//	freopen("in.txt","r",stdin);
//	cout<<"Hello world!"<<endl;
    int n,k;
    scanf("%d",&n);
    getchar();
    fgets(s,12,stdin);
    scanf("%d",&k);
    k--;
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[k])
            printf("%c",s[i]);
        else
            printf("*");
    }
	return 0;
}