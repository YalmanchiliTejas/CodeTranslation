#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,v=0,sea=0;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    for(int i=0;i<N;i++){
        if(v<=A.at(i)){
            v=A.at(i);
            sea++;
        }
    }
    cout<<sea<<endl;
}
