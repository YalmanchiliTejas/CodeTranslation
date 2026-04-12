
#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    int h[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &h[i]);
    }

    int ans = 1;
    bool f;
    for(int i = 1; i < n; i++){
        f = true;
        for(int j = 0; j < i; j++){
            if(h[j] <= h[i]){
                continue;
            }else{
                f = false;
                break;
            }
        }
        if(f == true){
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}