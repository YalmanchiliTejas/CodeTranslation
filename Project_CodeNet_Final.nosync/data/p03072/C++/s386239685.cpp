#include <bits/stdc++.h>
using namespace std;
int main(){
     int n, maxHeight=0, sum=0;
     cin >> n;
     int h[n];
     for (int i=0; i<n; i++) cin >> h[i];
     
     for(int j=0; j<n; j++) {
     
     	if(maxHeight <= h[j]) {
     	
     	  maxHeight = h[j];
     	  sum++;
     	}
     }
     
     cout << sum << endl;
}