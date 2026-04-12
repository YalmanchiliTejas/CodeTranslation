#include <bits/stdc++.h>
using namespace std;
int main() {
    int H,W,X,Y;
    cin>>H>>W;
    X=H;
    Y=W;
    string a[H];
    for(int i=0;i<H;i++){
        cin>>a[i];
    }
    vector<vector<char>> b(100,vector<char>(100));
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            b.at(i).at(j)=a[i].at(j);
        }
    }

    for(int i=X-1;i>-1;i--){
        bool x=true;
        for(int j=Y-1;j>-1;j--){
            if(b.at(i).at(j)=='#'){
              x=false;  
            }      
        }
        if(x){
            for(int k=i;k<X-1;k++){
                for(int j=Y-1;j>-1;j--){
                    b.at(k).at(j)=b.at(k+1).at(j);
                    b.at(k+1).at(j)=' ';    
                }
            }
            X--;
        }
    }
    for(int i=Y-1;i>-1;i--){
        bool x=true;
        for(int j=X-1;j>-1;j--){
            if(b.at(j).at(i)=='#'){
               x=false;
            }     
        }
        if(x){
            for(int k=i;k<Y-1;k++){ 
                for(int j=X-1;j>-1;j--){
                    b.at(j).at(k)=b.at(j).at(k+1);
                    b.at(j).at(k+1)=' ';
                }
            }
            Y--;
        }
    }

    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            cout<<b.at(i).at(j);
            if(j==Y-1)
              cout<<endl;
        }
    }
}