#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
#define SORT(c) sort((c).begin(),(c).end())
#define INF 1e9

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<bool> VB;

int main(void){
  int H,W; cin>>H>>W;
  vector<vector<char>> VVC(H,vector<char>(W,0));
  VB tatecheck(H,false);
  VB yokocheck(W,false);

  rep(i ,H){
    rep(t ,W){
      cin>>VVC[i][t];
      if(VVC[i][t] == '#'){
        tatecheck[i] = true;
        yokocheck[t] = true;
      }
    }
  }

  rep(p,H ){
    rep(q ,W){
      if(tatecheck[p] && yokocheck[q]){
        cout<<VVC[p][q];
      }
    }
    if(tatecheck[p])cout<<endl;
  }
}
