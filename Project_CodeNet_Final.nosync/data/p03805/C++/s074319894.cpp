#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
int main(){
  int n,m;cin>>n>>m;
  vector<P> nya(m);
  for(int i = 0; m > i; i++){
    cin >> nya[i].first>>nya[i].second;
  }
  vector<int> Pa(n);
  for(int i =0; n > i; i++){
    Pa[i] = i+1;
  }
  int ans = 0;
  do{
    bool ad = true;
    for(int i = 0; n-1 > i; i++){
      bool ok = false;
      for(int j = 0; m > j; j++){
        if(min(nya[j].first,nya[j].second) == min(Pa[i],Pa[i+1]) && max(nya[j].first,nya[j].second) == max(Pa[i],Pa[i+1])){
          ok = true;
          break;
        }
      }
      if(!ok){
        ad = false;
        break;
      }
    }
    if(ad)ans++;   
  }while(next_permutation(Pa.begin()+1,Pa.end()));
  cout << ans << endl;
}
