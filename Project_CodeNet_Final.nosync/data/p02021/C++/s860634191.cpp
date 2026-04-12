#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,sum,frag;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=a[j]-i;
            if(sum<0){
                cout<<i-1<<endl;
                goto fin;
            }
        }
    }
    fin:
    delete[] a;
}
