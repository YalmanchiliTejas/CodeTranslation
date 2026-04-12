#include <iostream>
using namespace std;

int main() {
	int n,p=0,c=1;
cin>>n;
int h[n+1];
for(int i=1;i<n+1;i++)
{ cin>>h[i];
 for(int j=1;j<i;j++)
 {
   if(h[j]>h[i])
   {c=0;
   break;}   
 }
 if(c==1)
   p++;
 c=1;
}
cout<<p;
	// your code goes here
	return 0;
}