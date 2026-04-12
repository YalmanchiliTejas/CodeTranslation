#include <bits/stdc++.h> 
 
using namespace std; 
 


int main() 
{


    string S;

    cin >>S;

  	bool flagB = false;
  	bool flagA = false;
    for(int i=0;i<3;i++){
      if(S.at(i)=='A')
        flagA=true;
      if(S.at(i)=='B')
        flagB=true;
    }
  
  	if(flagA&&flagB)
      cout<<"Yes"<<endl;
  	else
      cout<<"No"<<endl;

 

    return 0;
}