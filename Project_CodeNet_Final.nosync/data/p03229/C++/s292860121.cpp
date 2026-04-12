#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define in(x) cin >> x
#define out(str) cout << str << endl

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

long long N,lsum=0,rsum=0,mid,ans;

int main(){
    cin>>N;
    long long A[N];
    rep(i,N)cin>>A[i];
    sort(A,A+N);
    if(N%2==0){
        mid=N/2;
        rep(i,mid)lsum+=A[i];
        for(int i=mid;i<N;i++)rsum+=A[i];
        lsum*=2;
        rsum*=2;
        lsum-=A[mid-1];
        rsum-=A[mid];
        ans=rsum-lsum;
    }
    else{
        long long temp;
        mid=N/2+1;
        rep(i,mid)lsum+=A[i];
        for(int i=mid;i<N;i++)rsum+=A[i];
        lsum*=2;
        rsum*=2;
        lsum-=(A[mid-1]+A[mid-2]);
        temp=rsum-lsum;

        rsum=0;
        lsum=0;
        mid=N/2;
        rep(i,mid)lsum+=A[i];
        for(int i=mid;i<N;i++)rsum+=A[i];
        lsum*=2;
        rsum*=2;
        rsum-=(A[mid]+A[mid+1]);
        ans=max(temp,rsum-lsum);
    }
    out(ans);
}
