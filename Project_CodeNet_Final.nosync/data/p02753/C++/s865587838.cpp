        #include <iostream>
        #include<cmath>
        #include<string>
        using namespace std;
        int main()
        {
             string s;
             cin>>s;
             int a=0,b=0;
          int k=s.length();
          	for(int i=0;i<k;i++)
            {
              if(s[i]=='A')
                a++;
              else
                b++;
            }
          if(a==b+1 || b==a+1)
            cout<<"Yes";
          else
            cout<<"No";
            
        }