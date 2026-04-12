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
int N,M;int ans=0;int count=1;
cin >> N >> M;
for(int i=1;i<N;i++)count*=i;
bool check=false;
vector<int> a(M);
vector<int> b(M);
vector<int> order(N);
for(int i=0;i<N;i++){order.at(i)=i+1;}
for(int i=0;i<M;i++){cin >> a.at(i) >> b.at(i);}
do{
for(int i=0;i<N-1;i++)
{
check=false;
for(int j=0;j<M;j++)
{
if((a.at(j)==order.at(i)&&b.at(j)==order.at(i+1))||(a.at(j)==order.at(i+1)&&b.at(j)==order.at(i))){check=true;break;}
}
if(!check)break;
}
if(check)ans++;
count--;
if(count==0)break;
}while(next_permutation(order.begin(),order.end()));
cout << ans;
}
