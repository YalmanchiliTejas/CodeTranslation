#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main(){
ll n ;
cin >> n ;
int a[n] ;
for(int i=0 ; i< n ; i++)
{
    cin >> a[i] ;
}
ll s=0 ,cont=0 ;
for(int i=0 ; i< n ; i++)
{
   if(a[i]>=s)
   {
       cont++ ;
       s=a[i] ;
   }
}
cout << cont <<endl ;



 return 0  ;
}

