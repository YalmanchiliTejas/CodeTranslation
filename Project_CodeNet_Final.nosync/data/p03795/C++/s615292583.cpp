 #include <iostream>
 #include <math.h>
 #include <bits/stdc++.h>
  using namespace std;

 int main()
     {
  int n,res;
  cin>>n;
  if(n<15)
    {cout<<n*800;
  return 0;}

  res=(800*n)-(200*(n/15));
  cout<<res;
   return 0;
     }
