// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,i;
int main(){
    cin>>n>>m>>k;
    l=k;
    do{
        l+=m+k;
        i++;
    }while(l<n);
    if(l>n)i--;
    cout<<i<<endl;
    return 0;
}