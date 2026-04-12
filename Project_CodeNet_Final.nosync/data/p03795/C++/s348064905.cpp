#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int n  , sum = 0 , m;
    scanf("%d",&n);
    m = n / 15;
    sum = n * 800 - m * 200;
    printf("%d\n",sum);
    return 0;
}
