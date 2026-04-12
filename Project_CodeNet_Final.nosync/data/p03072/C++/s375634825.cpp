#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;cin>>N;
    vector<int>vec(N);
    int count=0;
    int m=0;
    for(int i=0;i<N;i++){
        cin>>vec[i];
        if(m<=vec[i]){
            m=vec[i];
            count++;
        }
    }
    cout<<count<<endl;
}