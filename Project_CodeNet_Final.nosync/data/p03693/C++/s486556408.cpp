#include<iostream>
#include<cmath>
using namespace std;
int main(){
   int num,ans;
   for(int i=2;i>=0;i--){
       cin>>num;
       ans+=num*pow(10,i);
   }
   if(ans%4==0) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   return 0;
}