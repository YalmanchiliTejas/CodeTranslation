#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int h,w;
    cin>>h>>w;
    int tate[101]={0};
    int yoko[101]={0};
    int map[101][101]={0};
    char c;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>c;
            if(c=='#'){
                map[i][j]=1;
            }
            else{
                yoko[i]++;
                tate[j]++;
            }
        }
    }
    /*for(int i=0;i<h;i++){
        cout<<yoko[i]<<endl;
    }*/
    for(int i=0;i<h;i++){
        if(yoko[i]!=w){
            for(int j=0;j<w;j++){
                if(tate[j]!=h){
                    if(map[i][j]==0){
                        cout<<'.';
                    }
                    else{
                        cout<<'#';
                    }
                }
            }
            cout<<endl;
        }
    }
}