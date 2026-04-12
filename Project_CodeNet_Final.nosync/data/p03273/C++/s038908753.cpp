#include <iostream>
using namespace std;

bool checkw(char c[100][100],int w, int i){
    for(int j=0;j<w;j++){
        if(c[i][j]=='#'){
            return true;
        }
    }
    return false;
}
bool checkh(char c[100][100],int h, int i){
    for(int j=0;j<h;j++){
        if(c[j][i]=='#'){
            return true;
        }
    }
    return false;
}

int main(){
    int h,w;
    char c[100][100];
    cin >> h >> w;
    for(int i = 0; i<h;i++){
        for(int j = 0; j<w;j++){
            cin >> c[i][j];
        }
    }
    char a[100][100];
    int n = 0;
    for(int i = 0; i<h;i++){
        if(checkw(c, w, i)){
            for(int k = 0; k < w;k++){
                a[n][k]=c[i][k];
            }
            n++;
        }
    }
    char ans[100][100];
    int m = 0;
    for(int i = 0; i<w;i++){
        if(checkh(a, n, i)){
            for(int k = 0; k < n;k++){
                ans[k][m]=a[k][i];
            }
            m++;
        }
    }
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}