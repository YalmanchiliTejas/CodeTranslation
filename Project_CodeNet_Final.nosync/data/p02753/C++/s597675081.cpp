#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
char a[5];
int main(){
    scanf("%s",a);
    if(a[0]==a[1]&&a[1]==a[2]){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}
