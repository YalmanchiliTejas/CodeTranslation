#include<bits/stdc++.h>
using namespace std;
int main()
{
//f<<":"<<endl;
     long long int n,i,j=1,c=0,f=1000000007,l,k,x=0,y,z,m,b,a=0;
     string s,w="",s1;
     char o;
     set <int, greater <int> > st;
     stack<string>sta,backk,forwardd;
     //int a[5];
    //long long  int arr[n+2][n+2];
     vector<char>ch(27);
     vector<string>str;
     vector<int>vect,vect3;
     map<long long int ,long long int>mp;
      cin>>n;
      for(i=0;i<n;i++)
      {
          cin>>k;
          vect.push_back(k);
          c+=k;
      }
      for(i=0;i<n;i++)
      {
          x+=vect[i];
         a=(a+((c-x)%f*(vect[i]%f)))%f;
      }
      cout<<a<<endl;
      }

