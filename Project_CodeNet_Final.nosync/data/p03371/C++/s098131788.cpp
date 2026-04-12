#include <math.h>
#include <iostream>
#include<string>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
int A,B,C,X,Y;
int ans=1000000000;
cin >> A >> B >> C >> X >> Y;
for(int i=0;i<2*max(X,Y)+1;i++)
{
int a=X-i/2;int b=Y-i/2;
if(i%2==1){a++;b++;}
if(a<0)a=0;if(b<0)b=0;
ans=min(ans,i*C+a*A+b*B);
}
cout << ans;
}
