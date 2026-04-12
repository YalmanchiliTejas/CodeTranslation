#include <cstdio>

using namespace std;

int v[200010],v1[200010];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    int st=1,dr=n;
    for(int i=n;i>=1;i--)
    {
        int nr=n-i+1;
        if(nr%2==1) {v1[st]=v[i];st++;}
        else {v1[dr]=v[i];dr--;}
    }
    for(int i=1;i<=n;i++)
        printf("%d ",v1[i]);
    return 0;
}
