#include<cstdio>
#include<algorithm>
using namespace std;
int n,s[100];

int main()
{
        scanf("%d",&n);
        if (n==0) return 0;
        for (int i=0;i<n;i++){
                scanf("%d",s+i);
        }
        sort(s, s+n);
        int k=0;
        for (int i=1;i<n-1;i++){
                k+=s[i];
        }
        k/=n-2;
        printf("%d\n",k);
        main();
}
  