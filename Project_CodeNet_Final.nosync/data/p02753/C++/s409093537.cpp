#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
     cin>>s;

       int A_s=0,B_s=0;

        for(int i=0;i<=2;i++)
        {
           if(s[i]=='A')
            A_s++;

            else
            B_s++;
        }
       if(A_s > 0 && B_s > 0)
         cout<<"Yes";

         else
         cout<<"No";
}
