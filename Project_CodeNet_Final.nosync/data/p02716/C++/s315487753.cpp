#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority_queue
#include<deque>//double_ended queue
#include<map>//map
using namespace std;
typedef long long LL; 
typedef pair<LL,LL> P;//Pでpair<-,->を表す。
const LL MAX=2000010;
const LL MOD=1000000007;
typedef map<LL,LL>::iterator Itr;

int main()
{ 
    LL n;
    cin>>n;
    LL a[n];
    for(int i=0;i<n;i++){cin>>a[i];}

    LL k=n/2;
    LL a1[k+1];//手前
    LL am[k+1];
    a1[0]=0;
    am[0]=0;
    for(int i=1;i<=k;i++){
        a1[i]=a1[i-1]+a[(i-1)*2];
        am[i]=max(am[i-1]+a[i*2-1],a1[i]);
    }
    if(n%2==0){cout<<am[k]<<endl;return 0;}

    LL b[n];
    for(int i=0;i<n;i++){b[i]=a[i];}
    reverse(b,b+n);
    LL b1[k+1];
    LL bm[k+1];
    b1[0]=0;
    bm[0]=0;
    for(int i=1;i<=k;i++){
        b1[i]=b1[i-1]+b[(i-1)*2];
        bm[i]=max(bm[i-1]+b[i*2-1],b1[i]);
        //cout<<b1[i]<<endl;
    }

    LL ans=0;
    for(int i=0;i<k;i++){
        ans=ans+a[i*2+1];
    }
    for(int i=0;i<k+1;i++){
        LL x=am[i]+bm[k-i];
        if(ans<x){ans=x;}
    }
    cout<<ans<<endl;
    return 0;
}