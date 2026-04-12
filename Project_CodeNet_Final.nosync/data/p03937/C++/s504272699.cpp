#include <cstdio>
int main()
{
    int h, w;
    int i, j;
    int count = 0;
    char s[10] = {0};
    scanf("%d %d", &h, &w);
    for(i = 0; i < h; i++){
        scanf("%s", s);
        for(j = 0; j < w; j++){
            if(s[j] == '#'){
                count++;
            }
        }
    }
    if(count == h + w -1){
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }
    return 0;
}
