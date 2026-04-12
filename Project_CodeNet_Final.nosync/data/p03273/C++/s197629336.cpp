#include <iostream>
#include <string>
using namespace std;

int main(){
    int h,w,i,j;
    cin >> h >> w;
    string a[h];
    for (i=0;i<h;i++){
        cin >> a[i];
    }

    for (i=0;i<h;i++){
        int f=0;
        for (j=0;j<w;j++){
            if (a[i][j] == '#'){
                f++;
            }
        }
        if (f == 0){
            for (j=0;j<w;j++){
                a[i][j] = '0';
            }
        }
    }
    for (j=0;j<w;j++){
        int f=0;
        for (i=0;i<h;i++){
            if (a[i][j] == '#'){
                f++;
            }
        }
        if (f == 0){
            for (i=0;i<h;i++){
                a[i][j] = '0';
            }
        }
    }

    for (i=0;i<h;i++){
        for (j=0;j<w;j++){
            if (a[i][j] == '0'){
                continue;
            }
            else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }
}
