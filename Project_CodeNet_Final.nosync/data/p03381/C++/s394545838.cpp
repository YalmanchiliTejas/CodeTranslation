#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int Xi;
    vector<int> X(N);
    for(int i=0;i<N;i++){
        cin >> Xi;
        X[i] = Xi;
    }
    auto X2 = X;
    sort(X2.begin(), X2.end());
    for(int i=0;i<N;i++){
        if(X[i] <= X2[(N-1)/2]) cout<<X2[(N)/2]<<endl;
        else                    cout<<X2[(N-1)/2]<<endl;
    }

    return 0;
}