import sys
input = sys.stdin.readline

sys.setrecursionlimit(10000)

N = int(input())
import bisect

L = [1]
ans = 1
for i in range(N):
    A = int(input())
    res = bisect.bisect_right(L, -A)
    if res != ans:
        L[res] = -A
    else:
        L.append(-A)
        ans += 1
print(ans)