from collections import deque
import bisect

N = int(input())
A = [int(input()) for i in range(N)]

ans = deque()
ans.append(A[0])

for a in A[1:]:
  if a <= ans[0]:
    ans.appendleft(a)
  elif a > ans[-1]:
    ans[-1] = a
  else:
    i = bisect.bisect_left(ans, a)
    ans[i - 1] = a

print(len(ans))
