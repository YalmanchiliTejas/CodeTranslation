#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int A[N],X[N];
    for(int i=0;i<N;i++){
    
        cin>>X[i];
        A[i]=X[i];
    }
    sort(X,X+N);

    for(int i=0;i<N;i++){
        if(A[i]<=X[N/2-1])cout<<X[N/2]<<"\n";
        else cout<<X[N/2-1]<<"\n";
    }

    return 0;
}
