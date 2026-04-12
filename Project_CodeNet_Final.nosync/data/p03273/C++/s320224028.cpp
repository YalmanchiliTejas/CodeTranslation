//2018.09.14 6min 1WA(cout消し忘れ)

#include <iostream>
using namespace std;

int main() {

    int H,W;
    cin >> H >> W;

    char a[H][W];
    int i,j,k;

    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cin >> a[i][j];
        }
    }


    bool del = true;
    for(i=1;i<=H;i++){
        for(j=1;j<=W;j++){
            if(a[i-1][j-1]=='#') del = false;
        }

        if(del){
            for(k=i;k<H;k++){
                for(j=1;j<=W;j++) a[k-1][j-1] = a[k][j-1];
            }
            H--;
            i--;
        }
        del = true;
    }

    for(j=1;j<=W;j++){
        for(i=1;i<=H;i++){
            if(a[i-1][j-1]=='#') del = false;
        }

        if(del){
            for(k=j;k<W;k++){
                for(i=1;i<=H;i++) a[i-1][k-1] = a[i-1][k];
            }
            W--;
            j--;
        }
        del = true;
    }

    for(i=1;i<=H;i++){
        for(j=1;j<=W;j++){
            cout << a[i-1][j-1];
        }
        cout << endl;
    }

    return 0;
}