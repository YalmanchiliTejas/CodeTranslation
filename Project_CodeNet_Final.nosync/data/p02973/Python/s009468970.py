N=int(input())
L=[1 for i in range(N+1)]
L[0]=-10**10

import bisect
for i in range(N):
    n=int(input())
    L[bisect.bisect_right(L,-n)]=-n
#print(L)
ans=0
for i in range(1,N+1):
    if L[i]==1:
        break
    ans+=1
print(ans)