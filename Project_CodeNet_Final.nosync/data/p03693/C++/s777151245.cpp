#include <bits/stdc++.h>
using namespace std;
 

	
int main() {
  int red, green,blue;
  cin >> red >> green >> blue;
  
  
  
  if(((red *100) + (green * 10) + blue) % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  
}


           