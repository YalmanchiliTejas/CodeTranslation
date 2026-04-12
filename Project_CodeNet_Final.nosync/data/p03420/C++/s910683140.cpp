#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SIZE=100005;

ll dat[SIZE];
void Add(int i){
  i++;
  while(i<SIZE){
    dat[i]++;
    i+=(i&-i);
  }
}

ll Get(int i){
  i++;
  ll res=0;
  while(i){
    res+=dat[i];
    i-=(i&-i);
  }
  return res;
}

ll N,K;
ll ans=0;

vector<ll> t;
void func(ll x){
  for(ll i=1;i*i<=x;i++){
    if(x%i==0){
      Add(i);

      if(x/i!=i)Add(x/i);
    }
  }
}

int main(){
  cin>>N>>K;

  
  for(ll i=N;i>=K;i--){

    if(N-i>0){
      func(N-i);
    }
    
    ll x=(N-i);
    //    ll y=t.end() - upper_bound(t.begin(),t.end(),i);

    ll y=Get(SIZE-2) - Get(i);
    if(i>0){
      ans+=x;
    }
    ans+= y;
  }
  cout<<ans<<endl;
  return 0;
}
