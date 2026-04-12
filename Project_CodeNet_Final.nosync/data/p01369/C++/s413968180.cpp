#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
char a[15]={'a','b','c','d','e','f','g','q','r','s','t','v','w','x','z'};
using namespace std;
int main(){
    char str[33]={0};
    while(1){
        scanf("%s",str);
        if(str[0] == '#')break;
        int len = 0;
        len = strlen(str);
        int cnt = 0;
        int x = 0;
        int f = 0;
        for(int i = 0;i < len; i++){
            for(int j = 0;j < 15; j++){
                if(str[i] == a[j]){
                    f = 1;
                    break;
                }
                else {
                    f = 0;
                }
            }
            if(i == 0){
                x = f;
                continue;
                }
            if(x == f){
                continue;
            }
            cnt++;
            x = f;
        }
        printf("%d\n",cnt);
    }
    return 0;
}