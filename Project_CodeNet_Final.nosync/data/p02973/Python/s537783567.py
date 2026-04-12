import bisect
import sys
input = sys.stdin.readline

N = int(input())
A = [-1*int(input()) for _ in range(N)]

maxims = [A[0]]
ans = 1
for a in A[1:]:
    if maxims[-1] > a:
        idx = bisect.bisect(maxims,a)
        maxims[idx] = a
    else:
        maxims.append(a)
        ans += 1
    
print(ans)
    
    
    