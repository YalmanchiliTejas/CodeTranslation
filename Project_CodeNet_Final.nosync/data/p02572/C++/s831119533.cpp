#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N;
    cin>>N;
    long long int lis[200003];
    long long int karizen=0;
    /*
    for(int i=0;i<N;i++){
        cin>>lis[i];
        karizen+=lis[i];
        karizen%=1000000007;
    }
    long long int ans=0;
    for(int i=0;i<N;i++){
        long long int pa=karizen-lis[i];
        pa%=1000000007;
        ans+=lis[i]*pa;
        ans%=1000000007;
    }
    */
    long long int ans=0;
    for(int i=0;i<N;i++){
        cin>>lis[i];
        karizen+=lis[i];
        karizen%=1000000007;
        if(i!=0){
            long long int pa=karizen-lis[i];
            pa+=1000000007;
            pa%=1000000007;
            ans+=lis[i]*pa;
            ans%=1000000007;
        }

    }
    cout<<ans<<endl;
    return 0;
}
