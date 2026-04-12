%:include <cstdio>
%:include <algorithm>
using namespace std;

int main() <%
  for(int tci = 0; ; tci++) <%
    int n; scanf("%d", &n);
    if(n==0) break;
    int minv = 1000, maxv=0, sum=0;
    for(int i = 0; i < n; i++) <%
      int x; scanf("%d", &x);
      minv=min(minv,x);
      maxv=max(maxv,x);
      sum+=x;
    %>
    printf("%d\n", (sum-maxv-minv)/(n-2));
  %>
  return 0;
%>