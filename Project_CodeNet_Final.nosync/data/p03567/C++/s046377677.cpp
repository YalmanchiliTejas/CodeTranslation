#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main(){
    char s[10];
    scanf("%s",s);
    int i,ans=0;
    for(i=0;i<=5;i++){
        if(s[i]=='A'&&s[i+1]=='C')ans=1;
    }
    
    if(ans==0)printf("No");
    else printf("Yes");
    
    return 0;
}
