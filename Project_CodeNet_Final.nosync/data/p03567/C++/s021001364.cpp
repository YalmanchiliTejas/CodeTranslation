#include<bits/stdc++.h>
using namespace std;
/*
    *
    * Prosen Ghosh
    * American International University - Bangladesh (AIUB)
    *
*/

/*int sum(int n){

      int sum=0;
      while(n!=0){
         sum=sum+n%10;
         n/=10;
      }
      int ans=0
      if((sum/10)==0){
         break;
      }
      else{
          ans=sum(sum(sum(n)));
      }
      return ans;
}*/
int main(){
        
       //char str[100000];
    string str;
       int cnt=0,cnt2=0;
       cin>>str;
       //scanf("%s",&str);
       for(int i=0;i<str.length();i++){
            if(str[i]=='A' && str[i+1]=='C'){
                 cout<<"Yes"<<endl;
                 //break;
                 return 0;
            }
            
       }


       cout<<"No"<<endl;
       return 0;
       

    return 0;
}