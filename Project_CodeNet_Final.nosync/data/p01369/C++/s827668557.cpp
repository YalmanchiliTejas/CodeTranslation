#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
int main(){
  char left[] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
  string s;
  while(1){
    cin >> s;
    if(s[0]=='#') break;
    int count = 0;
    int flag=-1;//left 0 right 1
    int mflag = -1;
    rep(i,s.size()){
      flag = -1;
      rep(j,15){
        if(left[j]==s[i]){
          flag = 0;
        }
      }
      if(flag==-1) flag = 1;
      if(i==0){
        mflag = flag;
      }else{
        if(mflag!=flag) count++;
      }
      mflag = flag;
    }
    cout << count << endl;
  }
}

