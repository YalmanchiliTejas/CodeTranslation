#include<bits/stdc++.h>

using namespace std;

int main(){

  int h,w;
  cin >> h >> w;
  string a[h];
  for(int hi=0;hi < h; hi++){
    cin >> a[hi];
  }

  vector<string> ans;  
  for(int hi=0;hi<h;hi++){
    bool ok=false;
    for(int wi=0;wi<w;wi++){
      if(a[hi][wi]=='#'){
	ok=true;
	break;
      }
    }
    if(ok) ans.push_back(a[hi]);    
  }
  vector<string> res; //column
  for(int wi=0;wi<w;wi++){
    bool ok=false;
    for(int hi=0;hi<ans.size();hi++){
      if(ans[hi][wi]=='#'){
	ok=true;
	break;
      }
    }
    if(ok){
      string tmp;
      for(int hi=0;hi<ans.size();hi++){
	tmp += ans[hi][wi];
      }
      res.push_back(tmp);      
    }	
  }
  for(int i=0;i<res[0].size();i++){
    for(int j=0;j<res.size();j++){
      cout << res[j][i];
    }
    cout << endl;
  }

  return 0;
  
}
