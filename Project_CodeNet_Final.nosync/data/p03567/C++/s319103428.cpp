
 #include<iostream>
 #include<stdio.h>
 #include<cstdlib>
 #include<cstdio>
 #include<string>
 #include<math.h>
 #include<time.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<fstream> 
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 #include<queue>
 #include<deque>
 #include<functional>
 #include<utility>
 #include<list>
 #include<memory>
 
 using namespace std;

 int main()
 {
   string s;
   while(cin>>s)
   {
     bool flag=false;
     for(int i=0;i<(s.length()-1);i++)
     {
       if(s[i]=='A'&&s[i+1]=='C') 
       {
         flag=true;
         break;                           
       }        
     } 
     if(flag) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
   } 
   return 0;
 }
 