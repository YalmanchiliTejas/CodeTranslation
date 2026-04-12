#include <iostream>

using namespace std;

int main(){
    int H,W;
    char a[100][100];
    bool f[100];
    cin >> H >> W;
    for(int i=0;i<H;i++){
        f[i] = true;
        for(int j=0;j<W;j++){
            cin >> a[i][j];
            if(a[i][j]!=46){
                f[i]=false;
            }
        }
    }
    bool g[100];
    for(int i=0;i<W;i++){
        g[i] = true;
        //cerr << a[i] << endl;
        for(int j=0;j<H;j++){
            if(a[j][i]!=46){
                g[i]=false;
                break;
            }
        }
    }
    for(int i=0;i<H;++i){
        if(f[i]) continue;
        for(int j=0;j<W;j++){
            //cerr << g[j] << " ";
            if(g[j]) continue;
            else  cout << a[i][j];
        }
        cout << "" << endl;
    }

    return 0;
}