using namespace std;
#include<iostream>
#include<cmath>

int main(){
    int N;
    cin>>N;
    int d[400000];
    for(int i=0;i<N;i++){
        cin>>d[i];
    }

    int MAX=0;
    int flagf=false;
    for(int i=0;i<N-1;i++){
        if(MAX<i) break;
        MAX=max(MAX,d[i]/10+i);
        if(MAX>=N-1){
            flagf=true;
            break;
        }
    }
    int MIN=N-1;
    int flagr=false;
    for(int i=N-1;i>0;i--){
        if(MIN>i) break;
        MIN=min(MIN,i-d[i]/10);
        if(MIN<=0){
            flagr=true;
            break;
        }
    }

    if(flagf&flagr) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    return 0;
}
