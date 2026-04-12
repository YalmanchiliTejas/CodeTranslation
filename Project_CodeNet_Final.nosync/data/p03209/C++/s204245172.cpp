#include<iostream>
using namespace std;
int64_t N,X;
#define LAYER(L) ((1LL<<(L+2))-3LL)
#define PATTY(L) ((1LL<<(L+1))-1LL)
int64_t solve(int N,int64_t X){
    if(X==1LL)return (N==0?1LL:0LL);
    if(X<=1LL+LAYER(N-1))return solve(N-1,X-1LL);
    if(X==1LL+LAYER(N-1)+1LL)return PATTY(N-1)+1LL;
    if(X<=1LL+LAYER(N-1)+1LL+LAYER(N-1))return PATTY(N-1)+1LL+solve(N-1,X-2-LAYER(N-1));
    else return PATTY(N-1)*2+1LL;
}
int main(void){
    cin>>N>>X;
    cout<<solve(N,X)<<endl;
    return 0;
}