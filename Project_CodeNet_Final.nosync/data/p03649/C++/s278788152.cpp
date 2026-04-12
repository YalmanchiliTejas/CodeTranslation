#include <iostream>

using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
#define MOD 1000000007

int main(){
    int N;
    lint A[50];
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    
    lint max=-1,cnt=0,cc=N+1;
    int mi;

    while(cc>N){
        cc=0;
        for(int i=0;i<N;i++){
            lint tmp=A[i]/N;
            cc+=tmp;
            cnt+=tmp;
            A[i]%=N;
            A[i]-=tmp;
        }
        for(int i=0;i<N;i++) A[i]+=cc;
    }
    
    for(int i=0;i<N;i++){
        if(max<A[i]){
            max=A[i];
            mi=i;
        }
    }
    while(max>=N){
        for(int i=0;i<N;i++) A[i]++;
        A[mi]-=N+1;
        max=-1;
        for(int i=0;i<N;i++){
            if(max<A[i]){
                max=A[i];
                mi=i;
            }
        }
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}