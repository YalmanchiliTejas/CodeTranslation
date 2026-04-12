#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, ok=1;

    cin >> N;

    int H[N];

    for(int lp; lp<N; lp++) cin >> H[lp];

    int premax = H[0];
    for(int lp=0; lp<N-1; lp++){
        if(premax <= H[lp+1]){
            ok++;
            premax = premax > H[lp+1] ? premax : H[lp+1];
        }
    }
    
    cout << ok << endl;
}