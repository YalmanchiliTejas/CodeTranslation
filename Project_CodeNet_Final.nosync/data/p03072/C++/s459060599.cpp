#include <bits/stdc++.h> 
using namespace std;
long long n, a[101];
int main(){
  cin >> n;
  int cnt = n;
  for(int i = 0;i < n; i ++){
    cin >> a[i];
	}
    for(int i = n; i > 0; i --){
      for(int j = 0; j < i; j++){
        if(a[i] < a[j]){
        cnt --;
        break;
		}
    }
  }
    cout << cnt+1;
	}