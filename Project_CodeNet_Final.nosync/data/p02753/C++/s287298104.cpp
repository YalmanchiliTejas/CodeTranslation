#include<bits/stdc++.h>
using namespace std;


int main()
{


                string s;

                cin>>s;


               int a=0,b=0,i=0;

               while(s[i]!='\0'){

                  if(s[i]=='A') a++;
                  else          b++;


                i++;
               }


             if(a==0 || b==0) cout<<"No"<<endl;
             else             cout<<"Yes"<<endl;



    return 0;
}
