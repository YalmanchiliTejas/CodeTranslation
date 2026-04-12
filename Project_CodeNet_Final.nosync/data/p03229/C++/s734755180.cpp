#include <bits/stdc++.h>
using namespace std;

int main() {
     long long N;
     cin>>N;
     vector<long long> A;
     for(long long i=0; i<N;  i++){
         long long a;
         cin>>a;
         A.push_back(a);
     }
     
sort(A.begin(),A.end());

long long res=0;
long long ares=0;
long long bres=0;
if(N%2==0){
    for(long long i=N-1; i>=N-((N/2)-1); i--){
        res+=2*A[i];
    }
    for(long long i=0; i<=(N/2)-1-1; i++){
        res-=2*A[i];
    }
    res+=A[N-((N/2)-1)-1];
    res-=A[(N/2)-1-1+1];
    cout<<res<<endl;
}
else{
    for(long long i=N-1; i>=N-1-(N/2-1)+1; i--){
        ares+=2*A[i];
    }
    for(long long i=0; i<=(N/2)-1; i++){
        ares-=2*A[i];
    }
    ares+=(A[N-1-(N/2-1)]+A[(N-1-(N/2-1)-1)]);
    
      for(long long i=N-1; i>=N-1-(N/2)+1; i--){
        bres+=2*A[i];
    }
    for(long long i=0; i<=(N/2)-1-1; i++){
        bres-=2*A[i];
    }
    bres-=(A[(N/2)-1]+A[(N/2)]);
    res=max(ares,bres);
    cout<<res<<endl;
}


}
