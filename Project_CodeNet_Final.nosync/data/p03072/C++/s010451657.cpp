#include <iostream>
using namespace std;
 
int main ()
{
	int n;
  	int h = 0;
  	int max = 0;
  	int cnt = 0;
  
  	cin >> n;
  	
  	for  (int i = 0; i < n; i++)
  	{
      cin >> h;
      
      if (h >= max)
      {
  		cnt++;
        max = h;
      }    
  	}
  
  	cout << cnt << endl;
  
	return 0;
}