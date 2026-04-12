#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,c,cntw;
  vector<pair<int,int> > V;
  while(1){
    cntw=0;
    cin >> n;
    if(n==0) break;
    for(int i=1;i<=n;i++){
      cin >> c;
      if(i%2==0){
	if(c==0&&V[V.size()-1].first==1) V[V.size()-1].first=0;
	else if(c==1&&V[V.size()-1].first==0) V[V.size()-1].first=1;
      }
      if(V.size()!=0&&c==0&&V[V.size()-1].first==0) V[V.size()-1].second++;
      else if(c==0) V.push_back(make_pair(c,1));
      else if(V.size()!=0&&c==1&&V[V.size()-1].first==1) V[V.size()-1].second++;
      else if(c==1) V.push_back(make_pair(c,1));
      while(1){
	int flag=0;
	if(V.size()>=2){
	  for(int j=0;j<V.size()-1;j++){
	    if(V[j].first==V[j+1].first){
	      V[j].second+=V[j+1].second;
	      V.erase(V.begin()+j+1);
	      flag=1;
	      break;
	    }
	  }
	}
	if(flag==0) break;
      }
    }
    for(int i=0;i<V.size();i++){
      if(V[i].first==0) cntw+=V[i].second;
    }
    cout << cntw << endl;
    V.clear();
  }
  return 0;
}