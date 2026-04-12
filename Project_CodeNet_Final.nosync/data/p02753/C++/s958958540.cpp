#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
using namespace std;
int dt[][2]= {{1,0},{-1,0},{0,1},{0,-1},{0,0}};
//typedef pair<int, int> P;
//priority_queue<int, vector<int>, greater<int> > q;
int main()
{
   IOS;
   string s;
   cin >> s;
   int n=s.length();
   int p1=0,p2=0;
   for(int i=0;i<n;i++){
       if(s[i]=='A')++p1;
       else ++p2;
   }
   int k=n/2;
   if((p1==k&&p2==k+1)||(p1==k+1&&p2==k)){
       cout<<"Yes";
   }
   else
   {
       cout<<"No";
   }
   
}
