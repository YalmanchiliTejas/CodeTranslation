#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;

typedef long long ll;

int all9(int digit, int notzero){
    int tmp = 1;

    if(digit < notzero || notzero < 0) return 0;

    rep(i, notzero){
        tmp *= digit - i;
        tmp /= i + 1;
    }

    rep(i, notzero){
        tmp *= 9;
    }

    return tmp;
}

int main(){

    string n;
    int k;
    cin >> n;
    cin >> k;

    int size = n.size();

    vector<int> nv(1);      //nの各桁をvectorに代入
    vector<int> notzero(1); //nを大きいほうの桁から見た時の0ではない桁の数

    int ans = 0;

    rep(i, size){
        nv.pback(n[i] - '0');

        if(n[i] == '0'){
            notzero.pback(notzero[i]);
        }else{
            notzero.pback(notzero[i] + 1);
        }
    }

    for(int i = 1; i <= size + 1; i++){

        if(i == size + 1){
            if(notzero[size] == k) ans++;
        }else if(i == size){

            if(nv[i] != 0){
                if(notzero[i - 1] == k){
                    ans++;
                }else if(notzero[i - 1] == k - 1){
                    ans += nv[i] - 1;
                }
            }

        }else{

            //左から桁目をnの左からi桁目の数未満の数とする

            if(nv[i] != 0){
                ans += (nv[i] - 1) * all9(size - i, k - 1 - notzero[i - 1]);
                ans += all9(size - i, k - notzero[i - 1]);
            }

        }

    }

    cout << ans << endl;

    return 0;
}
