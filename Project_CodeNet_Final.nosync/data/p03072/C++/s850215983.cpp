#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h>
#define  go return 0
#define pb push_back
#include<utility>
#include <algorithm>
#include<iterator>
#define lp(i, n)  for(int i=0; i<(int)(n); ++i)
#define all(v)   ((v).begin()), ((v).end())
#define sz(v)    ( (int)((v).size()) )
typedef long long ll;
typedef double db;
typedef vector<int> vi;
const int N=1e5+5;
int arr[N];
int main()
{

   int count=0,n,a=0;
   scanf("%d",&n);
   lp(i,n)
   scanf("%d",arr+i);

   lp(i,n)
   {
       if(arr[i]>=a){
        count++;
       a=arr[i];
       }
   }
   printf("%d",count);

go;
}
