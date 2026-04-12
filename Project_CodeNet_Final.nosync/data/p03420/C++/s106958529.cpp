#include <iostream>
using namespace std;

int main(){
    long long N,K;
    cin >> N >> K;

    long long cnt=0;
    for(int b=K+1;b<=N;b++){
        cnt+=((N+1)/b)*(b-K);
        cnt+=(((N+1)%b)-K>0?((N+1)%b)-K:0);
        if(K==0) cnt--;
    }

    cout << cnt << endl;
    return 0;
}