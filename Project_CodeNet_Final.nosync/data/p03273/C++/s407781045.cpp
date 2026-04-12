#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

inline int ctoi(char c){
  if(c == '#'){
    return 1;
  }
  else{
    return 0;
  }
}
inline char itoc(int x){
  if(x == 0){
    return '.';
  }
  else{
    return '#';
  }
}

void B(){
  int H,W;
  cin >> H >> W;
  vector<vector<int> > vec(H,vector<int>(W));
  vector<int> Hwise(H);
  vector<int> Wwise(W);
  vector<vector<int> >  sub(H,vector<int> (W));
  int cnt = 0;
  rep(i,H){
    rep(j,W){
      char c;
      cin >> c;
      vec[i][j] = ctoi(c);
    }
  }

  rep(i,H){
    rep(p,W){
    Hwise [i] += vec[i][p];
    }
  }
  rep(j,W){
    rep(q,H){
      Wwise[j] += vec[q][j];
    }
  }

  rep(i,H){
    if(Hwise[i]){// non-zero <-> no erase
      rep(j,W){
        if(Wwise[j]){
          cout << itoc(vec[i][j]);
        }
      }
      cout << endl;
    }
  }
}

int main() {
  B();
}
