#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#define rep(i,N) for(int i=0;i<N;i++)

long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;
long long a[51]={};


long long eat_patty(int N,long long x){
    long long ans;
    int n=N;
    if(N==0){
        if(x>0)return 1;
        else return 0;
    }
    if(x==1){
        return 0;
    }
    if(x<=1+a[N-1]){
        return eat_patty(N-1,x-1);
    }
    if(x==2+a[N-1]){
        return eat_patty(N-1,x-2)+1;
    }
    if(x<=2+2*a[N-1]){
        return eat_patty(N-1,a[N-1])+1+eat_patty(N-1,x-2-a[N-1]);
    }
    if(x==3+2*a[N-1]){
        return 2*eat_patty(N-1,a[N-1])+1;
    }
    return ans;
}


int main(){
int N;
long long X;
cin>>N>>X;
a[0]=1;
for(int i=1;i<=50;i++){
    a[i]=2*a[i-1]+3;
}
cout<<eat_patty(N,X);
 return 0;
}
/*
2 7

4

1 1

0


50 4321098765432109

2160549382716056

*/