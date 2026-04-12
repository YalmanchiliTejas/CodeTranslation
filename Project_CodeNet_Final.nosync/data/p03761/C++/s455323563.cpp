#include <cstdio>
#include <cstring>

#define MIN(X,Y) ((X)<(Y)?(X):(Y))

#define N 26

int main(void){
    char buf[51];
    int usable[N], chrcnt[N];
    int n;
    
    scanf("%d", &n);
    memset(usable, 0, sizeof(usable));
    scanf("%s", buf);
    for (char *p=buf; *p != '\0'; p++){
        usable[*p-'a']++;
    }
    for (int i=1; i<n; i++){
        scanf("%s", buf);
        memset(chrcnt, 0, sizeof(chrcnt));
        for (char *p=buf; *p != '\0'; p++){
            chrcnt[*p-'a']++;
        }
        for (int j=0; j<N; j++){
            usable[j] = MIN(usable[j], chrcnt[j]);
        }
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<usable[i]; j++){
            putchar('a'+i);
        }
    }
    puts("");
    
    return 0;
}
        