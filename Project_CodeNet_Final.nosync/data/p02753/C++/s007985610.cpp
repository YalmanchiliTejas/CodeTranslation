#include<bits/stdc++.h>
using namespace std;
string S;
int main()
{
    int count1=0,count2=0;
    cin>>S;
      for(int i=0;i<3;i++)
      {
          if(S[i]=='B')
            count1++;
            else if(S[i]=='A')
                count2++;
      }
      if(count1==3||count2==3)
      {
          cout<<"No"<<endl;
      }
      else
        cout<<"Yes"<<endl;
    return 0;
}
