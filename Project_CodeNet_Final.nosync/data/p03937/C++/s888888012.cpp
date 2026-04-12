#include <bits/stdc++.h>
using namespace std;

int x, y;
char a;
int ans;

int main(){   
   cin >> y >> x;
  
   for(int i = 0; i < x * y; i++){
           cin >> a;
           if(a == '#')
               ans++;   
    }
   
   	if(ans == x + y - 1)
       cout << "Possible" << '\n';
  	else
      cout << "Impossible" << '\n';
	return 0;
}