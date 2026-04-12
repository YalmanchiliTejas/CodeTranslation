#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#define mp make_pair
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	a=a*100+b*10+c;
	if (a%4==0) cout<<"YES"; else cout<<"NO";
	return 0; 
} 