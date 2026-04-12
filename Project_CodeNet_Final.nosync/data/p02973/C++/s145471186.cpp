#include<cstdio>
#include<cstring> 
#include<iostream>
#include<set>
using namespace std;
#define INF 1000000000
int a[100005];
int n,ans=0;
multiset<int>l;
multiset<int>::iterator q;
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
q=l.lower_bound(a[i]);
if(q==l.begin()){
l.insert(a[i]);
ans++;
}
else {
q--;
l.erase(q);
l.insert(a[i]);
}
}
printf("%d\n",ans);
}
