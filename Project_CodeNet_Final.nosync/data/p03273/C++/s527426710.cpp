#include<iostream>
using namespace std;

int main(){
    int H, W;
    int aH, aW;
    char m[100][100];
    char temp[100][100];
    char ans[100][100];
    cin >> H >> W;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> m[i][j];
        }
    }

    aH = 0;
    aW = 0;
    for(int i=0;i<H;i++){
        bool flag = false;
        for(int j=0;j<W;j++){
            if(m[i][j] == '#'){
                flag = true;
                break;
            }
        }
        
        if(flag){
            for(int j=0;j<W;j++){
              temp[aH][j] = m[i][j];
            }
            aH++;
        }
    }

    for(int j=0;j<W;j++){
        bool flag = false;
        for(int i=0;i<aH;i++){
            if(temp[i][j] == '#'){
                flag = true;
                break;
            }
        }

        if(flag){
            for(int i=0;i<aH;i++){
                ans[i][aW] = temp[i][j];
            }
            aW++;
        }
    }

    for(int i=0;i<aH;i++){
        for(int j=0;j<aW;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}