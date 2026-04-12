#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,maxn,minn,ave,sum = 0;

  while(cin >> n){
    if(n == 0) break;
    
    int *s = new int[n];

    cin >> s[0];
    maxn = minn = 0;
    for(int i = 1; i<n ; ++i){
      cin >> s[i];

      if(s[maxn]  <= s[i]){
	maxn = i;
      }
      if(s[minn] >= s[i]){
	minn = i;
      }

      
    }

    for(int i=0; i<n ; ++i){
      if(i != maxn && i != minn){
	sum += s[i];
      }
    }


    
    ave = sum/(n - 2);

    cout << ave << endl;

    sum = 0;
    ave = 0;
    
    delete[] s;
  }
  
  
  return 0;
}

