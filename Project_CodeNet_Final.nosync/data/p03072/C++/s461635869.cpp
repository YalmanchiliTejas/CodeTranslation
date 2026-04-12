#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  	vector <int> h(110);
  	rep(i,n){
    	cin>>h[i];
    }
  
  int ans=1;//一番目は必ず見えるから
  int highest=h[0];
  
  //2番目からループ
  for(int i=1;i<n;i++){
  	if(h[i]>=highest){
      ans++;
      highest=h[i];
      }	
   }
  
  cout<<ans<<endl;

}