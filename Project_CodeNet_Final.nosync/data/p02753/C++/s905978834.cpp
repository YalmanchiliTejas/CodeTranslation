#include <iostream> 
#include <bits/stdc++.h>
#include <vector> 
#include <algorithm> 
#include <string>
#include <cmath>
#include <iomanip> 
#include<climits> 
#include <utility>   
#include <set>
#include <numeric> 
#include <iterator>
#include <map> 
using namespace std; 
#define ll long long int
//typedef pair<ll,ll> p; 

int main() {
	
string s;
cin>>s;
int p=0;
for(int i=0;i<2;i++)
{
    if(s[i]!=s[i+1])
    p=1;
}
if(p==1)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
}