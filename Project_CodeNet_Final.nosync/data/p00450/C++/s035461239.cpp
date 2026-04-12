#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(){
  int n;
  while(cin >> n ,n){
    vector<P> mas;
    mas.clear();
    for(int i=1;i<=n;i++){
      int c; cin >> c;
      int back = mas.size() - 1;
      if(i % 2 == 1){
	if(mas.empty() || c != mas[back].first) mas.push_back(P(c,1));
	else mas[back].second++;
      }
      else {
	if(c != mas[back].first){
	  if(back == 0) {
	    mas[back].first = c;
	    mas[back].second++;
	  }
	  else {
	    int cnt = mas[back].second + 1;
	    mas.pop_back(); back--;
	    mas[back].second += cnt;
	  }
	}
	else mas[back].second++;
      }
    }
    int ans = 0;
    for(int i=0;i<mas.size();i++){
      if(mas[i].first == 0){
	ans += mas[i].second;
      }
    }
    cout << ans << endl;
  }
}