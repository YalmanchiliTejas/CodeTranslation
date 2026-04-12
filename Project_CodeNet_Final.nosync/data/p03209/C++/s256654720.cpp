#include<iostream>
#include<vector>
#define ll long long
using namespace std;


ll length[50];
ll p[50];

ll paty(int L,ll X){
    if(X == 0) return 0;
    if(L == 0) return 1;
    if(X <= length[L-1]+1) return paty(L-1,X-1);
    else return p[L-1] + 1 + paty(L-1,X-2-length[L-1]);
}

int main(){
    length[0] = 1;
    p[0] = 1;
    for(int i=1;i<50;i++){
        length[i] = 2*length[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }
    int N;
    ll X;
    cin >> N >> X;
    cout << paty(N,X) << endl;
    return 0;
}
