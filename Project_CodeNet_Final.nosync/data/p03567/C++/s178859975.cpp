#include<bits/stdc++.h>

int main(){
    int n;
    bool corr=false;
    char s[10];
    scanf("%s",s);
    for(int i = 0 ; i < strlen(s)-1  ; i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            corr=true;
        }
    }
    if(corr){
        printf("Yes");
    }
    else printf("No");
}
