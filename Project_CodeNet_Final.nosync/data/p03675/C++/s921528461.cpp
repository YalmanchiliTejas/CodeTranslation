#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    LL n,b[100005*2];
    cin>>n;
    for(int i=1;i<=n;i++){
        LL a,k;
        cin>>a;
        if(n%2==0){
            if(i%2==0){
                k=(n-i)/2;
            }else{
                k=(n+i)/2;
            }
        }else{
            if(i%2==0){
                k=(n+i)/2;
            }else{
                k=(n-i)/2;
            }
        }
        b[k]=a;
    }
    for(int i=0;i<n;i++){
        cout<<b[i];
        cout<<" ";
    }
}