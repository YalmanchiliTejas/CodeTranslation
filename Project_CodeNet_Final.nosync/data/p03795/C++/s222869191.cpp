#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
int d()
{
    int ret;
    scanf("%d", &ret);
    return ret;
}
long long lld()
{
    long long ret;
    scanf("%lld", &ret);
    return ret;
}
bool cmp(pair<int, int> s, pair<int, int> f)
{
    if (f.first > s.first)
        return true;
    else if (f.first == f.second && f.second < s.second)
        return true;
    else
        return false;
}
long long fact(long long n)
{
    if(n==1)
        return 1;
    return n * fact(n-1);
}
pair<int ,char>p;
pair<int ,char>p1;
pair<int ,char>p2;
int main(){
    int n=d();
    printf("%d\n",(n*800)-((n/15)*200));



}
