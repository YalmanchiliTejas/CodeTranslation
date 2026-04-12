#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    vector <string> a(x);
    for(int x1=0;x1<x;x1++){
        cin>>a.at(x1);
        
    }
    for(int x1=0;x1<x;x1++){
        
        if( (a.at(x1)).find("#")==string::npos){
            a.erase(a.begin()+x1);
            x--;x1--;
     }
    }
    
    for(int y2=0;y2<y;y2++){
        int k=0;
        for(int x2=0;x2<x;x2++){
            if( (a.at(x2))[y2]=='#' ){
                k=1;
                break;
            }
        }
        if(k==1){continue;}
        for(int x2=0;x2<x;x2++){
            (a.at(x2)).erase(y2,1);
            
        }y2--;y--;
        
    }
    
    for(auto &  x : a){
        for(auto & x1 :x){
            cout<<x1;
        }
        cout<<endl;
    }
} 
    