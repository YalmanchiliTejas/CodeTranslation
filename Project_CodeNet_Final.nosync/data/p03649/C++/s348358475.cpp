#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(long long int k=0;;){
        bool isok=true;
        auto it=max_element(a.begin(),a.end());
        if(*it<n){
            cout<<k<<endl;
            return 0;
        }
        long long int cnt=(*it)/n;
        k+=cnt;
        for(int i=0;i<n;i++){
            if(i!=it-a.begin()) a[i]+=cnt;
            else a[i]%=n;
        }
    }
    return 0;
}