#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a(28),b(28);
int ans=0;

bool check_point(vector<bool> reached,int next){
  if (reached.at(next-1)) return false;
  else return true;
}

int move(int now,vector<bool> reached,vector<bool> used_line,vector<bool> check){
  reached.at(now-1)=true;
  if (reached==check) {
    ans++;
  }
  
  for (int i=0;i<m;i++) {
    if (a.at(i)==now && used_line.at(i)==false && check_point(reached,b.at(i))) {
      used_line.at(i)=true;
      move(b.at(i),reached,used_line,check);
    }
    if (b.at(i)==now && used_line.at(i)==false && check_point(reached,a.at(i))) {
      used_line.at(i)=true;
      move(a.at(i),reached,used_line,check);
    }
  }
}

int main() {
  cin >> n>>m;
  for (int i=0;i<m;i++) cin>>a.at(i)>>b.at(i);
  vector<bool> reached(n,false),used_line(m,false),check(n,true);
  move(1,reached,used_line,check);
  cout<<ans<<endl;  
}