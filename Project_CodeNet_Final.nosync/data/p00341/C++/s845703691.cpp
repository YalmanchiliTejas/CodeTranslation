#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int,int>
#define VS vector<string>
#define VI vector<int>
#define ll long long
#define ull unsigned long long
#define FST first
#define SEC second
int main(){
  VI V;
  REP(i,12){
    int a;cin>>a;V.PB(a);
  }
  sort(ALL(V));
  if(V[0]==V[1]&&V[0]==V[2]&&V[0]==V[3]&&
     V[4]==V[5]&&V[4]==V[6]&&V[4]==V[7]&&
     V[8]==V[9]&&V[8]==V[10]&&V[8]==V[11]){
    cout<<"yes"<<endl;
  }else{
    cout<<"no"<<endl;
  }
  return 0;
}