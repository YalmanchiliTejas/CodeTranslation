/*================================================
# ~  file:A.cpp
# ~~ date:2020-03-09
# ~~~author: SoMnus_L
#        |everybody finds love,in the end|
#   人の運命か,人の希望は悲しみにつづられているね
=================================================*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define ll long long
const int N=1e6+10;
using namespace std;
typedef pair<int,int>PII;

string s;
int cnt1,cnt2;
int main(){
 ios::sync_with_stdio(false);
  cin>>s;
   for(int i=0;i<3;i++){
	if(s[i]=='A') cnt1++;
	else          cnt2++;
   }
   if((cnt1==2 && cnt2==1) || (cnt1==1 && cnt2==2))  cout<<"Yes"<<endl;
   else  cout<<"No"<<endl;
  return 0;
}
