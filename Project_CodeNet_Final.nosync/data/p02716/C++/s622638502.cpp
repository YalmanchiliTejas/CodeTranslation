#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,string>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;



int main(){
ll N;
cin >> N;
vector<ll> A(N,0);
for(ll i=0;i<N;i++){
  cin>>A[i]
;}
//Nが偶数
if(N%2==0){
  vector<ll> yes(N,0);
  vector<ll> no(N,0);
  yes[N-2]=A[N-2];
  no[N-2]=A[N-1];
  for(ll i=N-4;i>=0;i-=2){
    yes[i]=max(A[i]+yes[i+2],A[i]+no[i+2]);
    no[i]=A[i+1]+no[i+2]
  ;}
  cout<<max(yes[0],no[0])<<endl;
}
//Nが奇数
else if(N%2==1){
  vector<ll> yesp(N,0);
  vector<ll> yesm(N,0);
  vector<ll> nom(N,0);
  yesp[N-3]=A[N-1]+A[N-3];
  yesm[N-3]=A[N-3];
  nom[N-3]=max(A[N-2],A[N-1]);
  for(ll i=N-5;i>=0;i-=2){
    yesp[i]=yesp[i+2]+A[i];
    yesm[i]=max(yesm[i+2],nom[i+2])+A[i];
    nom[i]=max(nom[i+2]+A[i+1],yesp[i+2]);
  ;}
  cout<<max(yesm[0],nom[0])<<endl;
}
return 0;
}
