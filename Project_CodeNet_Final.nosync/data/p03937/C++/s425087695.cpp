#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W,seigen=0,ans=0,hante=0,count=0;
    vector<char> iti(70);

    cin>>H>>W;

    for(int i=0;i<H*W;i++){
        cin>>iti[i];
    }

    for(int i=0;i<H;i++){
         for(int j=0;j<W;j++){
            if(j<seigen&&iti[count]=='#'){
                ans=1;
                break;
            }
            if(iti[count]=='#'&&seigen<j){
                seigen=j;
            }
            count++;
        }
    }

    if(ans==1){ 
        cout<<"Impossible"<<endl;
    }else{
    cout<<"Possible"<<endl;        
    }
}