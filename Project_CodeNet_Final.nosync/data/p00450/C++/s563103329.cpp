#include <iostream>
#include <vector>
using namespace std;
typedef pair <int,int> P;
#define val first
#define num second

int main() {
  while(1) {
    int n;
    cin>>n;
    if(n==0) break;
    vector <P> mp;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      if(i==0) mp.push_back(P(a,1));
      else if(i%2==0) {
	if(mp.back().val == a) mp[mp.size()-1].num++;
	else mp.push_back(P(a,1));
      }
      else if(i%2==1){
	if(mp.back().val == a)mp[mp.size()-1].num++;
	else if(mp.size()==1) mp[0].val  = a,mp[0].num++;
	else mp[mp.size()-2].num += mp[mp.size()-1].num+1,mp.pop_back(); 
      }
    }

    int ans = 0;
    for(int i=0;i<mp.size();i++) 
      if(mp[i].val == 0) ans += mp[i].num;
    cout << ans <<endl;
  }
  return 0;
}