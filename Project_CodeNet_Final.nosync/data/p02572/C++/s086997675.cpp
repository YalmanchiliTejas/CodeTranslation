#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
    long int n;
    cin>>n;
    long long int *a;
    a=new long long int [n];
    long long int c=0,sum=0;
    long long int b=pow(10,9)+7;
    for(long int i=0;i<n;i++){
        cin>>a[i];
        c+=sum*a[i];
        c=c%b;
        sum+=a[i];
        sum=sum%b;
        }
    
    cout<<c<<endl;
}

