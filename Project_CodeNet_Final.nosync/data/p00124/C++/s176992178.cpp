#include<iostream>
using namespace std;

int main(){
  int t,w,l,d,s[10],r[10];
  string n[10];
  bool use[10],f = false;

  while(1){
    cin >> t;
    if(!t)break;
    if(f)cout << endl;
    f = true;

    for(int i=0;i<t;i++){
      cin >> n[i] >> w >> l >> d;
      s[i] = w*3 + d;
    }

    for(int i=0;i<t;i++)use[i] = false;
    
    for(int i=0;i<t;i++){
      int m = -1,pos = -1;
      for(int j=0;j<t;j++){
	if(!use[j]){
	  if(m<s[j]){
	    m = s[j];
	    pos = j;
	  }
	}
      }
      r[i] = pos;
      use[pos] = true;
    }

    for(int i=0;i<t;i++)cout << n[r[i]] << "," << s[r[i]] << endl;
  }
}