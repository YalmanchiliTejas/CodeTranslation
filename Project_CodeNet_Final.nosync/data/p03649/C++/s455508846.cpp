#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int main(){

    LL ans=0;

    int N;
    cin>>N;
    LL a[N];
    REP(i,N)cin>>a[i];

    bool last=true;

    while(last){
        last=false;
        LL cnt=0;
        REP(i,N){
            cnt +=a[i]/N;
            a[i]-=(a[i]/N)*(N+1);
        }
        ans+=cnt;
        REP(i,N){
            a[i]+=cnt;
            if(a[i]>=N)last=true;
        }
    }
    cout<<ans<<endl;


    return 0;
}