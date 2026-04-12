typedef long long ll;

#define shi5 100000+10
#define MOD 1000000007

#include <bits/stdc++.h>
using namespace std;
struct mystruct{
  long long v;
  mystruct * next;
};
int structcmp(const void *v1,const void *v2){return ((mystruct *)v1)->v - ((mystruct *)v2)->v;}
int intcmp(const void *v1,const void *v2){return *(int *)v1-*(int *)v2;}
long long minn(long long v1,long long v2){return v1<v2?v1:v2;}
long long maxx(long long v1,long long v2){return v1>v2?v1:v2;}
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  cout<<(x-z)/(y+z)<<endl;
  return 0;
}
