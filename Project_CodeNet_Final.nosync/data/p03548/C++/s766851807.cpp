using namespace std;
#include<bits/stdc++.h>
#define BEGIN ios_base::sync_with_stdio(0);cin.tie(0);
#define END return EXIT_SUCCESS;
#define FOR(I,A,B) for((I)=(A);(I)<(B);(I)++)
#define REP(I,N) FOR((I),0,(N))
#define UP(I,A,B) for((I)=(A);(I)<=(B);(I)++)
#define DW(I,A,B) for((I)=(A);(I)>=(B);(I)--)
#define IN(P) cin>>(P)
#define IN2(P1,P2) cin>>(P1)>>(P2)
#define IN3(P1,P2,P3) cin>>(P1)>>(P2)>>(P3)
#define INS(I,N,V) REP((I),(N)) cin>>(V[I])
#define INS2(I,N,V1,V2) REP((I),(N)) cin>>(V1[I])>>(V2[I]);
#define INS3(I,N,V1,V2,V3) REP((I),(N)) cin>>(V1[I])>>(V2[I])>>(V3[I]);
#define OUT(P) cout<<(P)<<endl
#define OUT2(P1,P2) cout<<(P1)<<" "<<(P2)<<endl
#define OUT3(P1,P2,P3) cout<<(P1)<<" "<<(P2)<<" "<<(P3)<<endl
#define OUTS(I,N,V) REP((I),(N)) cout<<(V[i])<<endl
#define ALL(C) (C).begin(),(C).end()
#define RALL(C) (C).rbegin(),(C).rend()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

int X,Y,Z,T;
inline void solve(){
  IN3(X,Y,Z);
  T=X/(Y+Z);
  OUT(T+(X-T*(Y+Z)>=Z?0:-1));
}

int main(int argc,char**argv){
  BEGIN
  solve();
  END
}
