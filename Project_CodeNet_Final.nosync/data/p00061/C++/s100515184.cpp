 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<math.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 #include<queue>
 #include<deque>
 #include<functional>
 #include<utility>
 
 using namespace std;
 
 struct stu
 {
   int num;
   int score;
   int rank;      
 };
 
 stu mm[10000+5];
 
 int comp(stu a,stu b)
 {
   return a.score>b.score;    
 }

 int main()
 {
   int n,m;
   char temp;
   int count=0;
   while(cin>>n>>temp>>m&&(n||m))
   {
     mm[count].num=n;
     mm[count].score=m;
     count++;                                
   }
   sort(mm,mm+count,comp);
   //for(int i=0;i<count;i++) cout<<mm[i].num<<endl;
   int count2=1;
   bool flag=false;
   for(int i=0;i<count;i++)
   {
     if(!flag)
     {
       mm[i].rank=1;
       flag=true;         
     }          
     else if(mm[i].score==mm[i-1].score)
     {
       mm[i].rank=mm[i-1].rank;     
     }
     else
     {
       count2++;
       mm[i].rank=count2;    
     }
   }
   int query;
   while(cin>>query) 
   {
     for(int i=0;i<count;i++)
     {
       if(mm[i].num==query)
       {
         cout<<mm[i].rank<<endl;
         break;                    
       }        
     }                  
   }
   //while(1);
   return 0;
 }