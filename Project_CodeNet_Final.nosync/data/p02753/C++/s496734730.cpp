#include <iostream>

using namespace std;

int main()
{
   char S[3];
	cin>>S;
    cout<<endl;
  if(S[0]==S[1])
  {
    if(S[0]==S[2]){
  	cout<<"No"<<endl;
    return 0;
    }
    else{
        	cout<<"Yes"<<endl;
    return 0;
    }
  }
  else{
  	cout<<"Yes"<<endl;
    return 0;
  }
}
