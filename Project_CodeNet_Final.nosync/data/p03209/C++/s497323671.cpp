#include<cstdio>
long long a[51];
long long p[51];
long long f(int n , long long x)
{
    if(n == 0)
        if(x <= 0)
            return 0;
        else
            return 1;
    else if(x <= 1 + a[n - 1])
        return f(n - 1, x - 1);
    else
        return p[n - 1] + 1 + f(n - 1 , x - 2 - a[n - 1]);
}
int main()
{
    int n;
    long long x;
   // freopen("burgers.in" , "r" , stdin);
    //freopen("burgers.out" , "w" , stdout);
    scanf("%d%lld" , &n , &x);
    p[0] = 1;
    a[0] = 1;
    for(int i = 1; i <= n ; i ++)
    {
        a[i] = a[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }
    printf("%lld" , f(n , x));
    return 0;

}
