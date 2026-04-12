#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int i,j,c,n,a[100001],ans,ch[100001];
  while(1){
    cin >> n;
    if(n == 0) break;
    ans = 0;
    cin >> a[1];
    if(!a[1]) ans++;

    c = 0;

    for(i=2;i<=n;i++){
      cin >> a[i];
      if(!a[i]) ans++;

      if(i % 2 == 0 && a[i] != a[i-1]){
	if(c < 2){
	  if(a[i]) ans = 0;
	  else ans = i;
	}
	else{
	  if(a[i]) ans -= i - ch[c-1];
	  else ans += i - ch[c-1];
	  c--;
	}
      }
      
      else if(a[i] != a[i-1]) ch[c++] = i;
      
    }
    
    cout << ans << endl;
    
  }
  return 0;
}

/*
	for(j=i-1;j>=0;j--){
	  if(a[i] == a[j]) break;
	  a[j] = a[i];
	  if(a[j]) ans--;
	  else ans++;
	}
 */