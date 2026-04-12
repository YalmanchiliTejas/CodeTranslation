#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;
static const int INF = (int)1e8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FIND(m,w) ((m).find(w)!=(m).end())

int main(void){
  int m,n;
  while(cin>>m>>n,m){
    vector<string> word(n);
    REP(i,n){
      cin>>word[i];
    }
    vector<int> member(m);
    REP(i,m)member[i] = i+1;
    int idx = 0;
    REP(i,n){
      if(member.size()==1) break;

      int number = i+1;
      string answord;
      if(number%15==0){
        answord = "FizzBuzz";
      }else if(number%5==0){
        answord = "Buzz";
      }else if(number%3==0){
        answord = "Fizz";
      }else{
        stringstream ss;
        ss<<number;
        answord = ss.str();
      }

      if(answord==word[i]){
        idx = (idx+1)%member.size();
      }else{
        member.erase(member.begin()+idx);
        if(idx==member.size())idx = 0;
      }
    }

    REP(i,member.size()){
      if(i)cout<<" ";
      cout<<member[i];
    }
    cout<<endl;
  }
  return 0;
}