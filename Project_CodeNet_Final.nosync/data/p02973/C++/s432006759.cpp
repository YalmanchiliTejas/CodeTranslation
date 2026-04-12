#include<bits/stdc++.h>
using namespace std;
void upd(vector<int> &t,int l,int r,int v,int x,int q){
  if(x+1<=l||x>=r)
    return;
  if(l==x&&r==x+1){
    t.at(v)=q;
    return;
  }
  int h=(l+r)/2;
  upd(t,l,h,v*2,x,q);
  upd(t,h,r,v*2+1,x,q);
  t.at(v)=max(t.at(v*2),t.at(v*2+1));
  return;
}
int que(vector<int> &t,int l,int r,int v,int lq,int rq){
  if(rq<=l||lq>=r)
    return 0;
  if(lq<=l&&rq>=r)
    return t.at(v);
  int h=(l+r)/2;
  return max(que(t,l,h,v*2,lq,rq),que(t,h,r,v*2+1,lq,rq));
}
int main(){
  int n;
  cin>>n;
  vector<vector<int>> ai(n);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    ai.at(i)={a,i};
  }
  sort(ai.begin(),ai.end());
  vector<int> c(n);
  c.at(ai.at(0).at(1))=0;
  int m=0;
  for(int i=1;i<n;i++){
    m+=(ai.at(i).at(0)>ai.at(i-1).at(0)?1:0);
    c.at(ai.at(i).at(1))=m;
  }
  m++;
  vector<int> t(m*4,0);
  int a=0;
  for(int i=0;i<n;i++){
    int q=que(t,0,m,1,c.at(i),m);
    a=max(a,q+1);
    upd(t,0,m,1,c.at(i),q+1);
  }
  cout<<a<<endl;
}