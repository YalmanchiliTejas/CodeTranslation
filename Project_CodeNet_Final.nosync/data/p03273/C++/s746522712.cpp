#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
#define ll long long
int main(){
    int H,W;
    cin >> H >> W;
    int i,j;
    string str;
    char a[H][W];
    for(i=0;i<H;i++){
      cin >> str;
      for(j=0;j<W;j++){
        a[i][j]=str[j];
      }
    }
    int rmh[H];
    int rmw[W];
    for(i=0;i<H;i++){
      rmh[i]=0;
    }
    for(j=0;j<W;j++){
      rmw[j]=0;
    }
    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
        if(a[i][j]=='#'){
          rmh[i]=1;
          rmw[j]=1;
        }
      }
    }
    for(i=0;i<H;i++){
      if(rmh[i]==1){
        for(j=0;j<W;j++){
          if(rmw[j]==1){
            cout << a[i][j];
          }
        }
        cout << endl;
      }
    }
    return 0;
}
