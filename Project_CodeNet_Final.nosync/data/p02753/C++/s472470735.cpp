    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
      char s[4];
      int n,i,a=0,b=0;
      cin>>s;
      
      for(i=0;i<3;i++)
      {
        
        if(s[i]=='A')
          a++;
        else
          b++;
      }
      	if(a!=0 && b!=0)
          cout<<"Yes";
      else
        cout<<"No";
      return 0;
    }