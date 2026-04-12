#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long int memo[100003][2];
int main(){
    for(int i=0;i<100003;i++)memo[i][0]=-1;

    long long int N,X,M;
    cin>>N>>X>>M;
    long long int ans=X;
    memo[ans][0]=1;memo[ans][1]=ans;
    int flg=0;
    for(long long int i=2;i<=N;i++){
        X=(X*X)%M;
        ans+=X;
        //printf("[%lld]:[%lld][%lld]\n",i,X,ans);
        if(memo[X][0]==-1||flg){
            memo[X][0]=i;memo[X][1]=ans;
        }
        else{
            long long int nokorite=N-i;
            long long int syuki=i-memo[X][0];
            long long int kasan=ans-memo[X][1];
            long long int syu=nokorite/syuki;
            i+=syuki*syu;
            ans+=kasan*syu;
            flg=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
