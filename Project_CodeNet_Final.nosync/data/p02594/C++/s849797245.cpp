#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//Factors of an num
/*
vector<ll> fact(ll n){
	vector<ll>v;
	for(int i=1;i*i<=n;i++){
		if(n%i ==0){
			v.push_back(i);
		
		if(i!=n/i)
			v.push_back(n/i);
	    }
	}

	return v;
}
*/


/*
Seive Of Eratos..
int N=1e5;
vector<bool> isprime(N+1,true);
void pri(int n){
	for(int i=2;i*i<=n;i++){
		if(isprime[i]){
			for(int j=i*i;j<=n;j+=i){
				isprime[j]=false;
			}
		}
	}
	return;
}
*/

/*
//Prime Factors
vector<bool> isprime(1e6+1,true);
 vector<int> primes;
 void sieve()
 {

    ll  i,j;
    isprime[0] = false;
    isprime[1] = false;

    for(i=2; i<=1e6 ;i++)
  {

    if(isprime[i])
    {

      primes.push_back(i);

      for(j=i*i; j<=1e6; j+=i)
      {
        isprime[j]=false;
      }

    }

  }
}

vector<int> primefactors(int  N)

 {

    vector<int> factors;
    ll pf_idx = 0, pf=primes[pf_idx];

    while(pf*pf<=N)
    {
        while(N % pf == 0)
        {
            N/=pf;
            factors.push_back(pf);
        }
        pf = primes[++pf_idx];
    }
    
    if(N != 1) factors.push_back(N);
    return factors;
}
 */   




int main(){
	 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int x;
  cin>>x;
  if(x>=30)
  	cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
 }


