#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<int> ch(100005);

int main() {
    ll N, X, M; cin >> N >> X >> M;

    if(X == 0){
        cout << 0 << endl;
        return 0;
    } else if(X == 1){
        cout << N << endl;
        return 0;
    }

    vector<ll> A;
    A.push_back(X);
    ch[X]++;
    ll st = 0;
    while(1){
        X *= X;
        X %= M;
        if(X == 0){
            A.push_back(0);
            break;
        } else if(X == 1) {
            A.push_back(1);
            break;
        }
        if(ch[X] == 0){
            ch[X]++;
            A.push_back(X);
        } else {
            st = X;
            break;
        }
    }

    ll n = A.size();
    ll total = 0;
    if(n > N){
        for (int i = 0; i < N; i++){
            total += A[i];
        }
        cout << total << endl;
        return 0;
    }

    rep(i, n){
        total += A[i];
    }

    if(A[n-1] == 0){
        cout << total << endl;
    } else if(A[n-1] == 1){
        cout << total + (N - n) << endl; 
    } else {
        ll f;
        rep(i, n){
            if(A[i] == st){
                f = i;
                break;
            }
        }
        ll total2 = 0;
        for (int i = f; i < n; i++){
            total2 += A[i];
        }
        ll k = n - f;
        ll nokori = N - n;
        ll roop = nokori / k;
        ll saigo = nokori % k;
        ll total3 = 0;
        for (int i = f; i < f+saigo; i++){
            total3 += A[i];
        }

        cout << total + total2*roop + total3 << endl;

    }


    return 0;
}