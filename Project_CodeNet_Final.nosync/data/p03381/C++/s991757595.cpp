#include <bits/stdc++.h>
using namespace std;

int X[300000];
int Xs[300000];

int main(){
    int N = 0;
    memset(X,0,sizeof(X));
    memset(Xs,0,sizeof(Xs));
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> X[i];
        Xs[i] = X[i];
    }
    sort(Xs,Xs+N);
    int lnum = Xs[N/2-1];
    int rnum = Xs[N/2];

    for(int i=0;i<N;i++){
        if(X[i] <= lnum) cout << rnum << endl;
        else if(X[i] >= rnum) cout << lnum << endl;
    }
    return 0;
}