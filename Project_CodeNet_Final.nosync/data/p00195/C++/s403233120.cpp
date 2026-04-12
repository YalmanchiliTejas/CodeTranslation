#include<bits/stdc++.h>
using namespace std;
int main()
{
   int am,pm,maxe,num;
   char arfabet[]="ABCDE";
   while(cin>>am&&cin>>pm&&am!=0&&pm!=0){
        maxe=am+pm;num=0;
        for(int i=1;i<5;i++){
            cin>>am>>pm;
            if(am+pm>maxe){
                maxe=pm+am;num=i;
            }

        }
         cout<<arfabet[num]<<" "<<maxe<<endl;
   }
}