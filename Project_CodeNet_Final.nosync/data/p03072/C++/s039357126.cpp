#include<bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<int> H(N);
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    int Max_h=-1;
    int count=0;
    for(int i=0;i<N;i++){
        if(Max_h<=H[i]){
            count++;
            Max_h=H[i];
        }
    }
    cout<<count<<endl;
    return 0;
}
