#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
int64_t burgers[51];
int64_t patis[51];
void PRE(){
    burgers[0]=1;
    for(int i=0;i<50;i++){
        burgers[i+1] = 2*burgers[i]+3;
    }

    patis[0]=1;
    for(int i=0;i<50;i++){
        patis[i+1]=2*patis[i]+1;
    }
}
int64_t BurgerS(int64_t n){
    /*
    if(n==0){
        return 1;
    }
    else{
        return 2*BurgerS(n-1)+3;
    }*/
    return 4*pow(2,n)-3;
}

/*
int64_t PatiS(int64_t n){
   return pow(2,n+1)-1;
}
*/
int64_t SliceP(int64_t n,int64_t x){//レベルnバーガーのxまでのパティの数
    if(n==0 && x==1){
        return 1;
    }
    if(x==0){
        return 0;
    }
    if(x-1>burgers[n-1]){
        return patis[n-1]+1+SliceP(n-1,x-burgers[n-1]-2);
    }
    else{
        return SliceP(n-1,x-1);
    }
}
int main(){
    int64_t n,x;
    cin>>n>>x;
    PRE();
   cout<<SliceP(n,x)<<endl;

}
