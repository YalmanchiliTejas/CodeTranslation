#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
   {
     ll n,i,j;
     string x;
     cin >> x;
     n=x.size();
     if(x[0]==x[2] && x[0]==x[1])
        cout << "No";
     else
        cout << "Yes";
   }
