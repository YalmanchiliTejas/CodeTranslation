#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    char a[110][110];
    for(int i = 1;i <= H;i++){
        for(int j = 1;j <= W;j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 1;i <= H;i++){
        bool C = false;
        for(int j = 1;j <= W;j++){
            bool A = true;
            for(int l = 1;l <= W;l++){
                if(a[i][l] == '#')A = false;
            }
            if(A == false){
                bool B = true;
                for(int l = 1;l <= H;l++){
                    if(a[l][j] == '#')B = false;
                }
                if(B == true);
                else{ cout << a[i][j];C = true;}
            }
        }
        if(C == true)cout << endl;
    }
}
