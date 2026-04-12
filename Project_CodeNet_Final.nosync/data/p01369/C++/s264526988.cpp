#include <bits/stdc++.h>

typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define DECIM8  fixed<<setprecision(8) 
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

using namespace std;
int main(void)
{
  map<char,int> qwerty;
  string q0="qwertasdfgzxcvb",q1="yuiophjklnm";
  REP(i,SZ(q0)) qwerty[q0[i]]=0;
  REP(i,SZ(q1)) qwerty[q1[i]]=1;
  for(;;){
    int answer=0;
    string s;
    cin >> s;
    if(s=="#") return 0;
    int last=0;
    REP(i,SZ(s)){
      if(i) answer+=qwerty[last]^qwerty[s[i]];
      last=s[i];
    }
    cout << answer << endl;
  }
}