#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll N, K; cin >> N >> K;
    ll ans = 0;
    if(K == 0){
        cout << N*N << endl;
        return 0;
    }

    for(int i = K+1; i <= N; i++){
        ll x = N % i; //あまり
        ll loop = N-x;//ループを構成する個数
        ll loopN = loop / i;//ループの数
        ll num = i-K;//1ループ内のK以上の個数
        ll tmp=0;
        if(num > 0) {
            tmp += num * loopN;
            //cout << i << "    " << num * loopN << endl;

            if(x >= K){
                tmp += x - K + 1;
                //cout << i << "       " << x - K + 1 << endl;
            }
        }
        ans+= tmp;
        //cout << " " << i << " loops:" << loopN << "  bigger than K:" << i-K << "  sum:" << tmp << endl;   
    }
    cout << ans << endl;
}