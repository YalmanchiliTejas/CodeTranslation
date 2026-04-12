#include <bits/stdc++.h>
using namespace std;



int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++){
      cin>>A[i];
    }
    int a=A[0];
    int count=1;
    for(int i=1;i<N;i++){
        if(A[i]>=a){
            count++;
            a=A[i];
        }
    }
    cout<<count<<endl;
}
