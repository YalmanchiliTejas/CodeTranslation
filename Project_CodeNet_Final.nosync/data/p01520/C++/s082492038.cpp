#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int N,T,E;
    int sand;
    cin>>N>>T>>E;
    for(int i=1;i<=N;i++){
        cin>>sand;
        if((T+E)%sand<=E){cout<<i<<endl;return 0;}
    }
    cout<<"-1"<<endl;
    return 0;
}