#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>a(1000,vector<char>(1000));
    vector<int>x(100);
    vector<int>y(100);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
      for(int i=0;i<100;i++){
          x[i]=0;
          y[i]=0;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                x[i]=1;
                y[j]=1;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(x[i]==0||y[j]==0){

            }
            else{
                cout<<a[i][j]<<flush;
            }
        }if(x[i]==1){
            cout<<endl;
        }
    }
    

    return 0;
}