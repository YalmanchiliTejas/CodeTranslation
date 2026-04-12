/*ॐॐ*/
/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different.
Change variable names or change some Data structres or anything just make sure MOSS do not
Detect Anything.
Yours Faithfully
Shobhit Yadav */

/* I do not fear this new challenge. Rather like a true warrior I will rise to meet it. 
                                       -Prince Vegeta  */

 /* “Strength is the only thing that matters in this world. Everything else is just a delusion for the weak.” – Vegeta */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 



ll N,M;
const ll int MOD = 1e9+7;
/*ll freq[200005];*/
void solve(){
   /*memset(freq,0,sizeof(freq));*/
  cin>>N;
  ll a[N];

  ll sum = 0;
  ll ans = 0;
  for(ll i = 0 ; i<N ; i++)
    cin>>a[i];


  sum = a[0];


  for(ll i = 1 ; i<N ; i++){
    ans += sum*a[i];
    ans %= MOD;
    sum += a[i];
    sum %= MOD;
  }

  cout<<ans%MOD<<'\n';




}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
   solve();

  return 0;
}
