#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void){
    int H,W;
    cin>>H>>W;
    string glaph[100];
    for(int i = 0; i<H; i++){
        cin>>glaph[i];
    }

    for(int i=0;i<H;i++){
        if(glaph[i].find('#')==string::npos){
            glaph[i]="hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
        }
    }

    for(int i=0; i<W;i++){
        bool flag=true;
        for(int j=0; j<H; j++){
            if(glaph[j][i]=='#'){
                flag=false;
            }
        }
        if(flag==true){
            for(int k=0; k<H;k++){
                glaph[k][i]='b';
            }
        }
    }

    for(int i=0;i<H;i++){
        if(glaph[i].find('h')<100)continue;
        for(int j=0; j<W;j++){
            if(glaph[i][j]=='b')continue;
            cout<<glaph[i][j];
        }
        cout<<endl;
    }


    return 0;
}