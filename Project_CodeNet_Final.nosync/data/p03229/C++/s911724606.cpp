#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>


long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){

vector<long long >v;
long long a;
int N;
cin>>N;

for(int i=0;i<N;i++){
    cin>>a;
    v.push_back(a);
}

sort(v.begin(),v.end());

long long ans=0;

//M型
int k=0;
while(N-k-1>k){
    ans+=v[N-k-1]*2;
    ans-=v[k]*2;
    k++;
}

if(N%2==0){
    ans-=v[k];
    k--;
    ans+=v[k];

}
else{
    ans-=v[k];
    k--;
    ans+=v[k];
}
long long Ans=0;
k=0;
//W型
while(N-k-1>k){
    Ans+=v[N-k-1]*2;
    Ans-=v[k]*2;
    k++;
}
if(N%2==0){
    k--;
    Ans+=v[k];
    k++;
    Ans-=v[k];
}
else{
    Ans+=v[k];
    k++;
    Ans-=v[k];
}
long long Answer=max(Ans,ans);

cout<<Answer<<endl;

 return 0;
}