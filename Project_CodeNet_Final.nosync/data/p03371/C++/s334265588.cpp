#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
#define BEGIN ios_base::sync_with_stdio(0);cin.tie(0)
#define END return EXIT_SUCCESS
#define FOR(I,A,B) for((I)=(A);(I)<(B);(I)++)
#define REP(I,N) FOR(I,0,N)
#define UP(I,A,B) for((I)=(A);(I)<=(B);(I)++)
#define DW(I,A,B) for((I)=(A);(I)>=(B);(I)--)
#define IN(P) std::cin>>(P)
#define IN2(P1,P2) std::cin>>(P1)>>(P2)
#define IN3(P1,P2,P3) std::cin>>(P1)>>(P2)>>(P3)
#define INS(I,N,V) REP(I,N) std::cin>>V[I]
#define OUT(P) std::cout<<P<<std::endl
#define OUT2(P1,P2) std::cout<<P1<<" "<<P2<<std::endl
#define OUT3(P1,P2,P3) std::cout<<P1<<" "<<P2<<" "<<P3<<std::endl
#define OUTS(I,N,V) REP(I,N) std::cout<<V[i]<<std::endl
#define ALL(C) (C).begin(),(C).end()
using namespace std;
using namespace __gnu_pbds;
long A,B,C,X,Y,ans;
inline void solve(){
  ans=1111111111;
  IN3(A,B,C);
  IN2(X,Y);
  ans=min(ans,A*X+B*Y);
  ans=min(ans,max(X,Y)*C*2);
  if(X>Y)ans=min(ans,Y*C*2+(X-Y)*A);
  else ans=min(ans,X*C*2+(Y-X)*B);
  OUT(ans);
}

int main(int argc,char**argv){
  BEGIN;
  solve();
  END;
}
