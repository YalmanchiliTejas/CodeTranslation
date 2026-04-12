#include <bits/stdc++.h>

using namespace std;
 
#define MD 1000000007
typedef long long int ll;

int main(){
    char data[101][101]={'\0'};
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>data[i][j];
        }
    }
    
    int d2_h=0,d2_w=w;
    char data2[101][101]={'\0'};
    for(int i=0;i<h;i++){
        int cnt_h=0;
        for(int j=0;j<w;j++){
            if(data[i][j]=='.'){
                cnt_h++;
            }
        }
        if(cnt_h!=w){
            for(int k=0;k<w;k++){
                data2[d2_h][k]=data[i][k];
            }
            d2_h++;
        }
    }
    
    int d3_h=d2_h,d3_w=0;
    char data3[101][101]={'\0'};
    for(int i=0;i<w;i++){
        int cnt_w=0;
        for(int j=0;j<d2_h;j++){
            if(data2[j][i]=='.'){
                cnt_w++;
            }
        }
        if(cnt_w!=d2_h){
            for(int k=0;k<d2_h;k++){
                data3[k][d3_w]=data2[k][i];
            }
            d3_w++;
        }
    }
    
    for(int i=0;i<d3_h;i++){
        for(int j=0;j<d3_w;j++){
            cout<<data3[i][j];
        }
        cout<<endl;
    }
    return 0;
}