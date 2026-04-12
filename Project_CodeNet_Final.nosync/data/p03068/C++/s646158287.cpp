#include <stdio.h>


int main(void){
    int n, k;
    char order[50];
    char s[20];
    
    fgets(order, 49, stdin);
    sscanf(order, "%d", &n);
    fgets(order, 49, stdin);
    sscanf(order, "%s", s);
    fgets(order, 49, stdin);
    sscanf(order, "%d", &k);
    //printf("%d %s %d\n", n, s, k);
    
    for(int i = 0; i < n; i++){
        if(s[k-1] == s[i]){
            continue;
        }else{
            s[i] = '*';
        }
    }
    printf("%s\n", s);
    
    return 0;
}