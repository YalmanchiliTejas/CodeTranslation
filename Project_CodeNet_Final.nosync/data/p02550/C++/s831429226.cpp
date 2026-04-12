#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
  ll N,X,M;


  cin >> N >> X >> M;


  ll ans=X;

  ll A = X;

  vector<ll> amari(M,-1);
  vector<ll> wa(0);

  amari[X] = 1;

  wa.push_back(0);
  wa.push_back(X);

  int roop_s = -1;
  int roop_e = -1;
  for(int i=2;i<=N;i++){


    A= (A*A)%M;

    ans+=A;

    

    wa.push_back(ans);



    if(amari[A]!=-1){

      roop_s = amari[A];
      roop_e = i-1;
      break;

    }
    else{

      amari[A] = i;
    }

  }


  if(roop_e!=-1){

    ll unit = wa[roop_e] - wa[roop_s-1];

    ll kuso_unit = wa[roop_s-1];


    ll K = N-(roop_s-1);

    ll sub = K/(1+roop_e -roop_s);

    ll sumo = K%(1+roop_e -roop_s);


    ll sumo_unit = wa[sumo+roop_s-1]- wa[roop_s-1];


    cout << sumo_unit+unit*sub+ kuso_unit << endl;

  }
  else{

  cout << ans << endl;;

  }



  return 0;
}
