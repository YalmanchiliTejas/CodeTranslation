#include <bits/stdc++.h>	
#define pb push_back
typedef long long ll;
const int inf = 2e9;
using namespace std;



int main(){
  int a,b,c,na,nb;
  scanf("%d%d%d%d%d",&a,&b,&c,&na,&nb);
  ll mi=1000000000000000001;
  int ca,cb;
  int tope=max(na,nb);
  for(int i=0; i<=tope; i++){

  	ca=na-i; cb=nb-i;

  	if(na-i < 0)ca=0;
  	if(nb-i < 0)cb=0;


  	mi=min(mi,ll(ll(i*c*2)+ll(ca*a)+ll(cb*b)));
  }

	return !printf("%lld",mi);

}
