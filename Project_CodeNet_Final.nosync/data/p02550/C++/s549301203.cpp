#include <iostream>
#include <string>
#include <vector>
#include <utility>

using ll=long long;
using namespace std;

int main(){
    ll N,X,M;
    cin>>N>>X>>M;
    ll save=X;

    vector<int> flag(M+1,0);
    int cnt=1;
    int loop;
    int st;

    while(1){
        //cout<<X<<endl;
        if(flag[X]!=0){
            loop=cnt-flag[X];
            st=flag[X];
            break;
        }else{
            flag[X]=cnt;
        }
        X*=X;
        X%=M;
        cnt++;
    }
    st--;
    //cout<<loop<<" "<<st<<endl;

    N-=st;
    if(N<=0){
        ll ans=0;
        X=save;
        for(int i=0;i<N+st;i++){
            ans+=X;
            X*=X;
            X%=M;
        }
        cout<<ans<<endl;
        return 0;
    }

    X=save;
    ll sum=0;
    for(int i=0;i<st;i++){
        sum+=X;
        X*=X;
        X%=M;
    }
    save=X;
    ll loopsum=0;
    for(int i=0;i<loop;i++){
        loopsum+=X;
        X*=X;
        X%=M;
    }

    ll last=N%loop;
    ll ans=sum+(N/loop)*loopsum;
    X=save;
    for(int i=0;i<last;i++){
        ans+=X;
        X*=X;
        X%=M;
    }

    cout<<ans<<endl;

    return 0;
}