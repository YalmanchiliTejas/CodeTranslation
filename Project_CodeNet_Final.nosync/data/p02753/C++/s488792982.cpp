#include<bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;

int main(){
    string S;
    cin>>S;
    int A=0,B=0;
    REP(i,3){
      if(S[i]=='A')A++;
      else B++;
    }
    if(A*B==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
