#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 10000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;


int main(){
    int N;
    cin>>N;
    ll A[110000],a[110000],b[110000],sum=0,x,ans=1000000000,ansa,ansb;

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A,A+N);

    for(int i=0;i<N;i++){
        if(i%2==0){
            a[i]=A[i/2];
            b[i]=A[N-1-i/2];
        }else{
            b[i]=A[i/2];
            a[i]=A[N-1-i/2];
        }
    }
    
    for(int i=0;i<N;i++){
        x=abs(a[(i+1)%N]-a[i]);
        ans=min(ans,x);
        sum+=x;
    }

    ansa=sum-ans;
    sum=0;
    ans=1000000000;

    for(int i=0;i<N;i++){
        x=abs(b[(i+1)%N]-b[i]);
        ans=min(ans,x);
        sum+=x;
    }
    ansb=sum-ans;
    cout<<max(ansb,ansa)<<endl;
}
