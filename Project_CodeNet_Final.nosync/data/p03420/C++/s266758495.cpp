#include <iostream>
#define ll long long
using namespace std;
int main () {
    ll N, M, ans=0;
    cin >> N >> M;
    for (int i=0;i<=N;i++){
        if (M==0){
            ans+=N*N;
            break;
        }
        int a=0;
        if (i-M>0){
            a=(N / i)*(i - M);
            if (N%i>=M)
                a+=N%i-(M-1);
        }
        ans+=a;
    }
    cout << "\n" << ans;
    return 0;
}