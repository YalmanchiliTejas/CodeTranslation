#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif
int d[256];
int main()
{
	
int n,an=0;
cin>>n;
int a[n],m=0;;
for(int i=0;i<n;i++){cin>>a[i];if(a[i]>=m){m=a[i];an++;}}

cout<<an<<endl;

}

