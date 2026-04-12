#include<cstdio>
#include<set>
using namespace std;
struct le{
bool operator()(int x,int y){
return x>y;
}
};
multiset<int,le> l;
multiset<int,le>::iterator p;

int a[100005];
int n;
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
p=l.upper_bound(a[i]);
if(p!=l.end())l.erase(p);
l.insert(a[i]);
}
printf("%d",l.size());
}