#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  while(1){
    char t;
    cin >> t;
    if(t=='#') return 0;
    vector<vector<pair<int,char>>> card(4,vector<pair<int,char>>(13));
    map<char,int> mp;
    repp(i,2,10) mp['0'+i]=i;
    mp['T']=10,mp['J']=11,mp['Q']=12,mp['K']=13,mp['A']=14;
    char x;
    rep(i,4){
      rep(j,13){ 
        cin >> x >> card[i][j].second;
        card[i][j].first=mp[x];
      }
    }
    int leader=0;
    int ew=0,ns=0;
    rep(i,13){
      char l = card[leader][i].second;
      pair<int,int> x={-1,-1};
      rep(j,4){
        if(card[j][i].second==l) x=max(x,{card[j][i].first,j});
      }
      rep(j,4){
        if(card[j][i].second==t) x={-1,-1};
      }
      rep(j,4){
        if(card[j][i].second==t) x=max(x,{card[j][i].first,j});
      }
      if(x.second%2){
        ew++;
      }else{
        ns++;
      }
      leader=x.second;
    }
    if(ew>ns) cout << "EW" SP ew-6 << endl;
    else cout << "NS" SP ns-6 << endl;
  }
  return 0;
}

