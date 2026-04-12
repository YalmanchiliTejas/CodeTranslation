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
 
 int main()
 {
   int N;
   int arr[20][20];
   while(cin>>N&&N)
   {
     for(int i=0;i<N;i++) for(int j=0;j<N;j++) arr[i][j]=0;
     int x=N/2+1;
     int y=N/2;
     int count=1;
     arr[x][y]=count++;
     while(count!=(N*N+1))
     {
       x++;
       y++;
       if(x<N&&y<N&&(arr[x][y]!=0))
       { 
         x--;
         y--;
         x=(x+2)%N;
         //cout<<x<<" "<<y<<endl;
         arr[x][y]=count++;
         //cout<<count<<endl;
       }
       else
       {
         if(x>=N) x=0;
         if(y>=N) y=0;
         //cout<<x<<" "<<y<<endl;
         if(arr[x][y]!=0)
         {
           x=(x-1+N)%N;
           y=(y-1+N)%N;
           x=(x+2)%N;
           arr[x][y]=count++;        
         }
         else arr[x][y]=count++;
       }          
     }          
     for(int i=0;i<N;i++)
     {
       for(int j=0;j<N;j++)
       {
         if(arr[i][j]<10) cout<<"   "<<arr[i][j];
         else if(arr[i][j]>=10&&arr[i][j]<=99) cout<<"  "<<arr[i][j];
         else cout<<" "<<arr[i][j];        
       }
       cout<<endl;        
     }      
   }
   //while(1);
   return 0; 
 }

 
  