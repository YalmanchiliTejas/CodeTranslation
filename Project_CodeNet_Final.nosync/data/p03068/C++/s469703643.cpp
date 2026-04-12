#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    char c[N];
    for(int i=0;i<N;++i)
        cin>>c[i];




    int K;
    cin>>K;
    for(int i=0;i<N;++i){
        if(c[i]==c[K-1])
            cout<<c[i];
        else
            cout<<"*";
    }
    cout<<endl;
}
