#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    int n=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
            if(a[i][j]=='#'){n++;}
        }
    }
    if(h+w-1==n){
        cout<<"Possible"<<endl;}
else{cout<<"Impossible"<<endl;}
        return 0;
   
      
}