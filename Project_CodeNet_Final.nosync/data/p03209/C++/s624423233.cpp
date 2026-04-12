#include <iostream>

typedef long long ll;

using namespace std;

int main(){
    ll b[51];
    ll p[51];
    ll d[51];
    ll N, K;
    ll ans = 0;
    cin >> N >> K;
    b[0] = 0;
    p[0] = 1;
    d[0] = 1;
    for(int i = 1; i < 51; i++){
        b[i] = 2 + 2*b[i-1];
        p[i] = 1 + 2*p[i-1];
        d[i] = 3 + 2*d[i-1];
    }
    
    while(N > 0){
        if(K == 1){
            break;
        }else if(K < d[N-1]+2){
            if(N == 1) ans+= 1;
            N--;
            K--;
        }else if(K == d[N-1]+2){
            ans+=(p[N-1] + 1);
            break;
        }else if(K < d[N]){
            ans+=(p[N-1] + 1);
            if(N == 1) ans+= 1;
            K -= (d[N-1]+2);
            N--;
        }else{
            ans+=(2*p[N-1] + 1);
            break;
        }
    }
    
    cout << ans << endl;
}