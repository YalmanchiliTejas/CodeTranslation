#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
  cin>>n;
  int max=INT_MIN;
  	int count=0;
  	int a[21]={0};
  	for(int i=0;i<n;i++)
    {
		cin>>a[i];
      if(a[i]>=max)
      {		max=a[i];
            count++;
      }
      
 
    }
  	cout<<count;
}
      
 