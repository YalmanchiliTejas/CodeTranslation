#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long width,jiange,gap,flag;
    while(~scanf("%lld %lld %lld",&width,&jiange,&gap))
    {
        flag = (width-gap)/(jiange+gap);
        printf("%lld\n",flag);
    }
    return 0;
}
