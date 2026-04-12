#include <bits/stdc++.h>

using namespace std;
#define loop(i,a,b) for(int i=(a); i<int(b); i++)
#define rep(i,b) loop(i,0,b)
#define all(c) (c).begin(), (c).end()

struct team {
  int id,s,rank;
};

bool comp(const team& a, const team& b){
  if(a.s!=b.s) return a.s > b.s;
  return a.id < b.id;
}

bool comp2(const team& a, const team& b){
  return a.id < b.id;
}

int main(){
  int i,s;
  vector<team> ts(200);
  rep(i,200){
    ts[i].s=0;
    ts[i].id=i;
  }
  
  while(scanf("%d,%d", &i, &s)){
    if(i==0&&s==0) break;
    ts[i].s+=s;
  }

  sort(all(ts),comp);

  rep(i,10){
    //cout << ts[i].id << " " << ts[i].s << endl;
  }
  
  ts[0].rank=1;
  int r=1;
  loop(i,1,200){
    if(ts[i].s==ts[i-1].s){
      ts[i].rank = r;
    } else {
      r++;
      ts[i].rank = r;
    }
  }

  rep(i,10){
    // cout << ts[i].id << " " << ts[i].s << " " << ts[i].rank << endl;
  }
  
  sort(all(ts),comp2);  

  int q;
  while(cin>>q){
    cout << ts[q].rank << endl;
  }

}