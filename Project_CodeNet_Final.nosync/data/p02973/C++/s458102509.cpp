#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)


using namespace std;

int main(){

int N;
cin>>N;

long long A[N];
rep(i,N){
    cin>>A[i];
}

vector<long long >v;

int ans=1;
v.emplace_back(A[0]);
long long max=A[0];
long long min=A[0];
for(int i=1;i<N;i++){
    if(A[i]<=min){
        v.emplace(v.begin(),A[i]);
        ans++;
    }
    else if(A[i]>max){
        v[ans-1]=A[i]; 
    }
    else{
        long long  it=lower_bound(v.begin(),v.end(),A[i])-v.begin();//A[i]以上の要素
        v[--it]=A[i];
    }
    max=v[ans-1];
        min=v[0];
}
//rep(i,ans)cout<<v[i]<<" ";
cout<<ans<<endl;
    
 return 0;
}
/*
5
2
1
4
5
3

2


4
0
0
0
0

4



*/