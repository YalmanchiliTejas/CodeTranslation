#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
  	cin >> n;
  	int ma = 0 , ans = 0;
 	for(int i = 0 ; i < n ; i++)
    {
		int x;
      	cin >> x;
      	if(x >= ma){ 
          ans++;
          ma = x;
        }
      	
    }
  	cout << ans << endl;

 	return 0; 
}