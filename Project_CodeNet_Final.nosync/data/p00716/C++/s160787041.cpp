#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<climits>
#include<map>
#include<set>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define INF 1<<30
using namespace std;
typedef pair<double,int> P;
typedef pair<int,P> PP;

int main(){
  int n;
  int a,c;
  double b;
  unsigned long long Max;
  cin >> n;
  while(n-- > 0){
    Max = 0;
    unsigned long long mon;
    int year,num;
    vector<PP> va;


    cin >> mon >> year >> num;
    rep(i,num){
      cin >> a >> b >> c; 
   
      unsigned long long B,A,C;
      A = mon;
      C = 0;
      rep(i,year){
	B = A * b;
	if(a == 0){ // TAN
	  C = C + A * b;
	  A = A - c;
	}else if(a == 1){ // HUCK
	  A = A + B - c;
	}
      }
      if(a == 0)A = A + C;
      Max = max(Max,A);
    }


    cout << Max << endl;


  }
return 0;
}