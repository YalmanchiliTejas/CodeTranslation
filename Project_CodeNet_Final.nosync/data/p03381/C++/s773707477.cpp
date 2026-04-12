#include<bits/stdc++.h>
using namespace std;

int a[200005];
vector<int> aa;

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",a+i);
    aa.push_back(a[i]);
  }
  sort(aa.begin(), aa.end());
  int ml = aa[n/2 - 1], mr = aa[n/2];
  for(int i=0;i<n;i++) {
    if(a[i] <= ml) printf("%d\n",mr);
    else printf("%d\n",ml);
  }
}
