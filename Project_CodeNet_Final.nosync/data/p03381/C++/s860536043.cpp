#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n],B[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
        B[i]=A[i];
}
    sort(A,A+n);
    for(int i=0;i<n;i++){
        if(B[i]<=A[n/2-1]){
            cout<<A[n/2]<<endl;
        }else {cout<<A[n/2-1]<<endl;}
    }
}
