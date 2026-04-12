#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
int main(void)
{
  map<char,int> scnum;
  FOR(i,2,10) scnum['0'+i]=i;
  scnum['T']=10;
  scnum['J']=11;
  scnum['Q']=12;
  scnum['K']=13;
  scnum['A']=14;
  for(;;){
    string tr;
    cin >> tr;
    if(tr=="#") return 0;
    vector<vector<string> > card(4,vector<string>(13));
    REP(i,4) REP(j,13) cin >> card[i][j];
    int lead=0;
    int ns=0;
    REP(j,13){
      int str[4]={};
      REP(i,4){
	if(card[i][j][1]==card[lead][j][1]) str[i]+=50;
	if(card[i][j][1]==tr[0]) str[i]+=100;
	str[i]+=scnum[card[i][j][0]];
      }
      int tmps=0;
      int sucl=0;
      REP(i,4) if(tmps<str[i]){
	tmps=str[i];
	sucl=i;
      }
      if(sucl%2==0) ++ns;
      lead=sucl;
    }
    if(ns>6) cout << "NS " << ns-6 << endl;
    else cout << "EW " << 7-ns << endl;
    
  }
}