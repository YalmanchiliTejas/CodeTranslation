//Xcode main は一つまで
//競プロのデバッグにでも使おう
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
long long N,X;
long long a[51];

long long L(long long n,long long x){
    if(n==0) return 1;
    if(x==0) return 0;
    if(x>1 && x<(a[n]+1)/2) return L(n-1,x-1);
    if(x==(a[n]+1)/2) return L(n-1,a[n-1])+1;
    if(x>(a[n]+1)/2 &&  x<a[n])return 1+L(n-1,a[n-1])+L(n-1,x-(a[n]+1)/2);
    if(x==a[n]) return 2*L(n-1,a[n-1])+1;
    else return 0;
}


int main() {
    cin>>N>>X;
    a[0]=1;
    for(int yy=1;yy<=50;yy++){
        a[yy]=2*a[yy-1]+3;
    }
    
    cout<<L(N,X)<<endl;
    
    return 0;
}
