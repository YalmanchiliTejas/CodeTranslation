#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[4];
    scanf("%s",a);
    if(a[0]==a[1]&&a[1]==a[2])
        printf("No");
    else
        printf("Yes");
    return 0;
}
