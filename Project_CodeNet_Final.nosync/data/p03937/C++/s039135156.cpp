#include <bits/stdc++.h>

using namespace std;

int main(){
 int h,w;
  cin >> h >> w;
  string a;
  int res=0;
  for(int i=0;i<h;i++){
    cin >> a;
   for(int j=0;j<w;j++){
    if(a[j]=='#') res++;
   }
  }
 
  if(res==h+w-1) cout << "Possible" << endl;
  else  cout << "Impossible" << endl;

}
