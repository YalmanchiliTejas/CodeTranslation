
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
   int x,y,z;
   while(cin>>x>>y>>z)
   {
     int n=(int)(1.0*(x-z)/(y+z));
     cout<<n<<endl; 
   }
   return 0;
 }
 