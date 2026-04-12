#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;cin>>N;
    vector<long long>vec(N);
    long long sum=0;
    for(int i=0;i<N;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    sort(vec.begin(),vec.end());
    long long s=0;
    for(int i=0;i<N/2;i++)s+=vec[i];
    long long m=sum-s;
    if(N%2==0){
        cout<<(m-vec[N/2])*2+vec[N/2]-(s-vec[N/2-1])*2-vec[N/2-1]<<endl;
    }
    if(N%2==1){
        long long x=(m-vec[N/2]-vec[N/2+1])*2+vec[N/2]+vec[N/2+1]-s*2;
        long long y=(m-vec[N/2])*2-(s-vec[N/2-1])*2-vec[N/2]-vec[N/2-1];
        cout<<max(x,y)<<endl;
    }
}