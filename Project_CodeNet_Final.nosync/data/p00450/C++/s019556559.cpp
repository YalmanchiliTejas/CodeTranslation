#include<vector>
using namespace std;
#define BLACK 1
#define WHITE 0
#define REP(i,b,e) for(int i=(int)b;i<(int)e;i++)
#define rep(i,n) REP(i,0,n)

class state{
public:
  int num,color;
  state(){};
  state(int tnum,int tcolor){num=tnum;color=tcolor;}
  void change(){color = color==WHITE?BLACK:WHITE;}
};

void solve(vector<state>& A,int flag,int color){
  if ( flag == 0){
    if ( A.size() != 0 && A[A.size()-1].color == color)A[A.size()-1].num++;
    else A.push_back(state(1,color) );
  }else {
    if (  A[A.size()-1].color == color)A[A.size()-1].num++;
    else {
      A[A.size()-1].num++;
      A[A.size()-1].change();
      if ( A.size() <= 1)return;
      if ( A[A.size()-1].color == A[A.size()-2].color){
	A[A.size()-2].num+=A[A.size()-1].num;
	A.erase(A.begin()+A.size()-1);
      }
    }
  }
}

main(){
  int n;
  while(cin>>n&&n){
    vector<state> A;
    rep(i,n){
      int t;
      cin>>t;
      solve(A,i%2,t);
    }
    int cnt=0;
    rep(i,A.size()){
      if ( A[i].color==WHITE)cnt+=A[i].num;
    }
    cout << cnt<<endl;
  }
  return false;
}