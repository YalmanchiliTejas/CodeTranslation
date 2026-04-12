/**************************
 *   Saidur Rahman Sajol  *
 * Dept. of CSE,IUBAT(162)*
 **************************/
#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0.0)
#define l long
#define ll long long 
#define ul unsigned long
#define ull unsigned long long

ull minimum(ull a,ull b){
  return (a<b)?a:b;
}
ull maximum(ull a,ull b){
  return (a>b)?a:b;
}
ull great(ull a,ull b){
	if(b==0) return a;
  return great(b,a%b);
}
vector<int>stl;
vector<int>stl1;
set<int>pb;
map<char,int>mp;
vector<pair<int,int> >freak;
vector<pair<int,int> >freak1;

int main(){
	string s;
	cin>>s;
	string sa="AC";
	if(s.find(sa)!=(-1)) puts("Yes");
	else puts("No");
	return 0;
}
