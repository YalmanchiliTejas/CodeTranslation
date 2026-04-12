#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    char a[100];
    while(~scanf("%s",a)){
        if(a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u'){
            printf("vowel\n");
        }
        else{
            printf("consonant\n");
        }
    }
    return 0;
}
