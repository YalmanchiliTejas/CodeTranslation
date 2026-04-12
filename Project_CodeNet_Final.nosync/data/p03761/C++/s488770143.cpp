
      #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=mod*mod;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
ll min(ll a,ll b){
  if(a>b){
    return b;
    }
      else{
        return a;
      }
  }
  
  ll max(ll a,ll b){
    if(a>b){
      return a;
    }
    else{
      return b;
    }
  }

ll power(ll a,ll b){
 ll ans=1;
 for(ll i=1;i<=b;i++){
ans*=a;
  }
  return ans;
}

 ll gcd(ll m,ll n){
 	if(n==0){
       return m;
     }
   return gcd(n,m%n);
 }
ll lcm(ll a,ll b){
  ll g=gcd(a,b);
  return a/gcd(a,b)*b;
		

}
int main(){
  ll N;
  cin>>N;
  
  vector<string>S(N);
  vector<ll>date(26);
  rep(i,N){
    cin>>S[i];
  }

  rep(i,S[0].size()){
date[S[0][i]-'a']++;
  }


rep(i,N){
vector<ll>T(26);
  rep(j,S[i].size()){
    T[S[i][j]-'a']++;
  }
  
  rep(j,26){
if(date[j]>T[j]){
  date[j]=T[j];
}
  }
}


rep(i,date.size()){
  char s='a'+i;
  rep(j,date[i]){
    cout<<s;
  }
}

cout<<endl;
} 
    

 
