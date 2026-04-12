#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main(){
    long long int n;
    cin>>n;
    vector<long long int >a;
    for(long long int i=0;i<n;i++){
        long long int s;
        cin>>s;
        a.push_back(s);
    }
    vector<long long int >sum;
    for(long long int i=0;i<n;i++){
        sum.push_back(a[i]);
    }
    for(long long int i=n-2;i>0;i--){
        a[i]=(a[i]%M+a[i+1]%M)%M;
    }
    long long int Count=0;
    for(long long int i=0;i<n-1;i++){
        Count+=(a[i+1]%M*sum[i]%M)%M;
    }
    cout<<Count%M;
}