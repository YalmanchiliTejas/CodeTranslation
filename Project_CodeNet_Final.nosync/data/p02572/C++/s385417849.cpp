#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
//#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

const long long INF=1000000007; 

int main(){
    long int N;
    cin>>N;
    long long A[N];
    for (long int i=0;i<N;i++) cin>>A[i];
    long long sum=0,sum2=0;
    for (long int i=0;i<N;i++){
        sum+=A[i];
        sum2+=(A[i]*A[i])%INF;
        sum=sum%INF;
        sum2=sum2%INF;
    }
    sum=sum*sum;
    sum=sum%INF;
    long long ans=sum-sum2;
    if (ans<0) ans+=INF;
    if (ans%2==0){
        ans=ans/2;
        cout<<ans<<endl;
    }
    else{
        ans=(ans+INF)/2;
        cout<<ans<<endl;
    }
    return 0;
}