#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,p ,z;
    cin>>a;
   if(a/15>=1)
   {
       z=a/15;
     p=(11800*z)+(a-(z*15))*800;
     cout<<p;
   }
   else
   {
      p=a*800;
      cout<<p;
   }
	return 0;
	}



