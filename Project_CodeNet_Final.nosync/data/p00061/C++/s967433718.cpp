#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Team{
public:
  int num;
  int ans;
  bool operator < (const Team &s)const{
    if(ans==s.ans) return num<s.num;
    else return ans<s.ans;
  }
};

main(){
  Team data[100000];
  int i;
  for(i=0;;i++){
    scanf("%d,%d", &data[i].num, &data[i].ans);
    if(data[i].num==0 && data[i].ans==0) break;
  }
  sort(data, data+i);
  reverse(data, data+i);
  map<int, int> ans;
  for(int j=1, k=1;j<i;j++){
    if(data[j-1].ans!=data[j].ans) ans[data[j-1].num]=k++;
    else ans[data[j-1].num]=k;
    if(j==i-1){
      ans[data[j].num]=k;
    }
  }
  int q;
  while(cin >> q){
    cout << ans[q] << endl;
  }
  return 0;
}