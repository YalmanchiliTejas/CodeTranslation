#include <bits/stdc++.h>
using namespace std;



int main(){
    int N,M,result=0;
    cin>>N>>M;
    vector<pair<int,int> > R(M);
    for(int i=0;i<M;i++){
        cin>>R.at(i).first>>R.at(i).second;
    }
    vector<int> n(N-1);
    for(int i=0;i<N-1;i++){
        n.at(i)=i+2;
    }
    do{
        bool y=false;
        for(int i=0;i<M;i++){
            if(R.at(i).first==1&&n.at(0)==R.at(i).second){
                y=true;
            }
        }
        if(y){
            bool x=true;
            for(int i=0;i<N-2;i++){
                for(int j=0;j<M;j++){
                    if((R.at(j).first==n.at(i)&&R.at(j).second==n.at(i+1))||(R.at(j).second==n.at(i)&&R.at(j).first==n.at(i+1))){
                        break;
                    }
                    if(j==M-1){
                        x=false;
                    }
                }
            }
            if(x){
                result++;
            }
        }
    }
    while(next_permutation(n.begin(),n.end()));
    cout<<result<<endl;
    
}