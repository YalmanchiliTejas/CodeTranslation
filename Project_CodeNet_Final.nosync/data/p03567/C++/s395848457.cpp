#include<bits/stdc++.h>
using namespace std;

bool Substring(string s, string sub)
{
    int l1=s.length();
    int l2=sub.length();
    int i, j, k;
    for(int i=0;i<=l1-l2;i++)
    {
        k=i;
        for(j=0;j<l2;j++)
        {
            if(s[k]!=sub[j])
            {
                break;
            }
            k++;
        }
        if(j==l2)
        {
            return true;
        }
    }
    return false;
}


int main()
{
      string s;
      cin>>s;
      string sub="AC";
      bool isSub=Substring(s, sub);
      if(isSub)
      {
          cout<<"Yes"<<endl;
      }
      else 
      {
          cout<<"No"<<endl;
      }
    


    return 0;
}