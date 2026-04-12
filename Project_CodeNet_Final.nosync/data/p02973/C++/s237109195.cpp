#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll BIG=1e15;


int main(){
    int N; cin>>N;
    vector<ll> d(N); for(int i=0;i<N;i++) cin>>d.at(i);

    vector<ll> r(N+1);

    for(int i=0;i<N; i++) r.at(i)=-1;
    for(int i=0;i<N;i++){
        if(r.at(0)<d.at(i)) r.at(0)=d.at(i);
        else{
            int NG=0,OK=N;
            while(NG<OK-1){
                int MID=(NG+OK)/2;
                if(r.at(MID)<d.at(i)) OK=MID;
                else NG=MID;
            }
            r.at(OK)=d.at(i);
        }
    }
    int minus=N, plus=0;
    while(plus<minus-1){
        int MID=(minus+plus)/2;
        if(r.at(MID)==-1) minus=MID;
        else plus=MID;
    }
    cout<<plus+1<<endl;
}