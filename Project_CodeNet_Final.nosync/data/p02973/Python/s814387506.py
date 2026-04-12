import sys
from collections import deque
import time
import bisect
def input():
    return sys.stdin.readline()[:-1]
n=int(input())
a=[int(input()) for i in range(n)]
# print(a)
ans=deque([a[0]])
for i in range(1,n):
    loc=bisect.bisect_left(ans,a[i])
    if loc==0:
        ans.appendleft(a[i])
    else:
        ans[loc-1]=a[i]
# print(ans)
print(len(ans))