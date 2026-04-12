#include <bits/stdc++.h>
using namespace std;

//関数


    
    
    
//main関数
int main() {
    
    
    //入力
    int H,W;
    cin>>H>>W;
    vector<int> count(H+W-1);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char hoge;
            cin>>hoge;
            //cout<<hoge<<endl;
            if(hoge=='#'){
                count.at(i+j)++;
            }
        }
    }
    
    bool poss=true;
    for(int i=0;i<H+W-1;i++){
        if(count.at(i)!=1){
            poss=false;
        }
    }
    
    //出力
    if(poss){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
}
