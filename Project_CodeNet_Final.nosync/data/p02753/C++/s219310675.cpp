#include <cstdio>

using namespace std;

int main() {
    char a[4]={};
    int i, sum=0;
    scanf("%s", a);
    for(i=0;i<3;i++)
    {
        if(a[i]=='A')
            sum++;
    }
    if(sum%3)
        printf("Yes");
    else
        printf("No");
    
    return 0;
}