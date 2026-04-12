
#include <cstdio>

int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    char a[h][w];
    bool b[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf("\n%c",&a[i][j]);
            b[i][j] = true;
        }
    }

    int count_a_r;
    int count_b_r;
    for(int j = 0; j < h; j++){
        count_a_r = 0;
        count_b_r = 0;
        for(int k = 0; k < w; k++){
            if(b[j][k] == true){
                count_b_r++;
                if(a[j][k] == '.'){
                    count_a_r++;
                    continue;
                }else if(a[j][k] == '#'){
                    break;
                }
            }
        }
        if(count_a_r == count_b_r){
            for(int l = 0; l < w; l++){
                b[j][l] = false;
            }
        }
    }

    int W = w;
    int count_a_c;
    int count_b_c;
    for(int j = 0; j < w; j++){
        count_a_c = 0;
        count_b_c = 0;
        for(int k = 0; k < h; k++){
            if(b[k][j] == true){
                count_b_c++;
                if(a[k][j] == '.'){
                    count_a_c++;
                    continue;
                }else if(a[k][j] == '#'){
                    break;
                }
            }
        }
        if(count_a_c == count_b_c){
            for(int l = 0; l < h; l++){
                b[l][j] = false;
            }
            W--;
        }
    }

    int count_w = 0;
    for(int i = 0; i < h; i++){
        count_w = 0;
        for(int j = 0; j < w; j++){
            if(b[i][j]){
                printf("%c",a[i][j]);
                count_w++;
            }
            if(count_w == W){
                printf("\n");
                break;
            }
        }
    }

    return 0;
}