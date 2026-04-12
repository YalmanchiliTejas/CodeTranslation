#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vector<ll> n_layers(51), n_buns(51);

ll sub(int N, ll X) {
  //N==0のときXを返す
    if (N == 0) { return X; }
    //X<=1なら0
    if (X <= 1) return 0;
    else if (X <= n_layers[N-1]+1) return sub(N-1, X-1);
    else if (X == n_layers[N-1]+2) return n_buns[N-1] + 1;
    else if (X <= n_layers[N]-1) return n_buns[N-1] + 1 + sub(N-1, X-n_layers[N-1]-2);
    else {return n_buns[N];}
}


int main() {
  
    n_layers[0] = n_buns[0] = 1;
    for (int i=1; i<=50; i++) {
        n_layers[i] = n_layers[i-1]*2 + 3;
        n_buns[i] = n_buns[i-1]*2 + 1;
    }


    int N; ll X;
    cin >> N >> X;
    cout << sub(N,X) << endl;
    return 0;
}
