#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int H,W;
    cin >> H >> W;
    char a[H][W];
    int i,j,k,l,m,line;
    l=0,m=0,line=-1;
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cin >> a[i][j];
        }
    }
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            for(k=0;k<W;k++){
                if(a[i][k]=='#'){
                    l=1;
                }
            }
            for(k=0;k<H;k++){
                if(a[k][j]=='#'){
                    m=1;
                }
            }
            if(l==1&&m==1){
                if(i!=line&&line!=-1){
                    cout << endl;
                }
                cout << a[i][j];
                line=i;
            }
            l=0;
            m=0;
        }
    }
}
