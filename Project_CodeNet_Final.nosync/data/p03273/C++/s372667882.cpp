#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    int h, w;
    scanf("%d %d", &h, &w);
    char a[h][w];
    for(int i = 0; i < h; i++){
        scanf("%s", a[i]);
    }
    int r[h], c[w];
    fill(r, r + h, 0);
    fill(c, c + w, 0);
    for(int i = 0; i < h; i++){
        int sm = 0;
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                r[i]++;
                break;
            }
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if(a[j][i] == '#'){
                c[i]++;
                break;
            }
        }
    }

    for(int i = 0; i < h; i++){
        if (r[i] != 0) {
            for(int j = 0; j < w; j++){
                if(r[i] != 0 && c[j] != 0){
                    cout << a[i][j];
                }
            } 
            puts("");           
        }
    }   
}