#include<iostream>
#include<cmath>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long int N,X,M;
    cin>>N>>X>>M;
    long long int len=min(N,M+1);
    long long  int arr[len];
    long long int rem=X;
    for(long long int i=0;i<len;i++){
        arr[i]=rem;
        long int temp=rem;
        temp=temp*temp;
        rem=temp%M;
    }
    
    long long int total=0;
    if(len==N){
        for(long long int i=0;i<len;i++){
            total=total+arr[i];
        }
        cout<<total<<endl;
        return 0;
    }
    
    long long int index=-1;
    for(long long int i=0;i<len-1;i++){
        if(arr[i]==arr[len-1]){
            index=i;
            break;
        }
    }
    
    long long int prev=0;
    for(long long int i=0;i<index;i++){
        prev+=arr[i];
    }
    
    long long int interval=0;
    for(long long int i=index;i<len-1;i++){
        interval+=arr[i];
    }
    
    
    long long int ilen=(len-2)-index+1;
    N=N-index;
    total=total+prev;
    long long int cnt=N/ilen;
    total=total+interval*cnt;
    long long int rest=N%ilen;
    for(long long int i=index;i<index+rest;i++){
        total+=arr[i];
    }
    
    cout<<total<<endl;
    return 0;
}