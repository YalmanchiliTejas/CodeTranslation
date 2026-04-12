#include <iostream>

using namespace std;

int main(){
  
  int a[50];
  int n, l, r, j;
  int cnt_in;
  int ans[10000] = {0};

  for(;;){
    cin >> n >> l >> r;
    if(n == 0 && l == 0 && r == 0){
      break;
    }
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    
    for(int i = l; i <= r; i++){
      for(j = 0; j < n; j++){
	if(i % a[j] == 0){
	  if((j+1) % 2 == 1){
	    ans[cnt_in]++;
	  }
	  break;
	}
      }
      if(j == n){
	if(n % 2 == 0){
	  ans[cnt_in]++;
	}
      }
    }

    cnt_in++;

  }

  for(int i = 0; i < cnt_in; i++){
    cout << ans[i] << endl;
  }

  return 0;
}

