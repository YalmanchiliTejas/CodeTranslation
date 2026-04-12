#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pii pair<int,ii>
#define st first
#define nd second
#define mp make_pair
#define N 100005
using namespace std;

int n,x,y,ata[N];
ll ans;
vector<ii> xs,ys;
vector<pii> yol;

int bul(int node) {
  if(ata[node]==node) return node;
  return ata[node]=bul(ata[node]);
}

int main() {
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
    scanf("%d %d",&x,&y);
    xs.push_back(mp(x,i));
    ys.push_back(mp(y,i));
    ata[i]=i;
  }
  sort(xs.begin(),xs.end());
  sort(ys.begin(),ys.end());
  for(int i=0;i<xs.size()-1;i++) {
    int fs=xs[i].nd;
    int ss=xs[i+1].nd;
    int cs=xs[i+1].st-xs[i].st;
    yol.push_back(mp(cs,mp(fs,ss)));
  }
  for(int i=0;i<ys.size()-1;i++) {
    int fs=ys[i].nd;
    int ss=ys[i+1].nd;
    int cs=ys[i+1].st-ys[i].st;
    yol.push_back(mp(cs,mp(fs,ss)));
  }
  sort(yol.begin(),yol.end());
  for(int i=0;i<yol.size();i++) {
    int n1=yol[i].nd.st;
    int n2=yol[i].nd.nd;
    if(bul(n1)!=bul(n2)) {
      ata[ata[n1]]=ata[n2];
      ans+=yol[i].st;
    }
  }
  printf("%lld",ans);
}
