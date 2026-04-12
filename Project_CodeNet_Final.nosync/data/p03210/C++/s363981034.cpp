#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#include<algorithm>
#include<queue>
typedef long long ll;
#include<vector>
#define cin(n) scanf("%lld",&(n))
#define cout(n) printf("%lld",(n))
#define couc(c) printf("%c",(c))
#define coutn printf("\n")
#define cout_ printf(" ")
const int MAXN= 1e4 + 5 ;
ll n;
int main()
{
    cin(n);
    if(n==7||n==5||n==3)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
