#include <iostream>
using namespace std;
int main()
{
    int n,k,i;
    char c;
    char str[20];
    cin>>n;
    scanf("%s",str);
    cin>>k;
    c=str[k-1];
    for(i=0;i<=n-1;i++) if(str[i]!=c) str[i]='*';
    printf("%s",str);
    return 0;
}
