#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,a;

  for(;;){
    cin >> n;
    if(!n)break;

    vector<int> color;
    vector<int> num;
    for(int i=1;i<=n;i++){
      cin >> a;
      if(color.empty()){
	color.push_back(a);
	num.push_back(1);
      }else{
	if(!(i&1) && color.back()!=a){
	  color[(int)color.size()-1] = a;
	  num[(int)num.size()-1]++;
	  if(color.size()>1){
	    num[(int)num.size()-2] += num[(int)num.size()-1];
	    color.erase(color.begin()+(int)color.size()-1);
	    num.erase(num.begin()+(int)num.size()-1);
	  }
	}else{
	  if(color.back()==a)num[(int)num.size()-1]++;
	  else{
	    color.push_back(a);
	    num.push_back(1);
	  }
	}
      }
    }
    int ans = 0;
    for(int i=0;i<(int)color.size();i++)
      if(!color[i])ans += num[i];
    cout << ans << endl;
  }
}