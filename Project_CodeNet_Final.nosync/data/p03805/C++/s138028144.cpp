#include<cstring>
#include<iostream>
#include<set>
using namespace std;

int n,m,ans=0;

set<int> s[10];
void search(bool res[], int cur){
  bool check=true;
  for(int i=0;i<n;i++){
    if(!res[i]){
      check=false;
      if(s[cur].find(i)!=s[cur].end()){
        bool tmp[9];
        for(int j=0;j<n;j++){
          tmp[j] = res[j];  
        }
        tmp[i]=true;
        search(tmp, i);
      }
    }
  }
  if(check)ans++;
}

int main(){
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    a--;b--;
    s[a].insert(b);
    s[b].insert(a);
  }
  bool tmp[9];
  memset(tmp, false, sizeof(tmp));
  tmp[0] = true;
  search(tmp, 0);
  cout << ans << endl;
}