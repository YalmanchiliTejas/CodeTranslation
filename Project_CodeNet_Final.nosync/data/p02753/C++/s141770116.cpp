#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  char v[3];
  
  for(int i=0;i<3;i++)
  {
  	cin >> v[i];
  }
  
  if(v[0]==v[1])
  {
	if(v[1]==v[2])
  	{
    	cout << "No" <<endl;
  	}
    else{
      cout <<"Yes"<<endl;
    }
  }
  else
  {
    cout <<"Yes"<<endl;
  }
    
    return 0;
    
}