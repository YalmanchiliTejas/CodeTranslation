from collections import deque

N = int(input())
A = list(map(int, input().split()))

q = deque()
for i in range(N):
  a = A[i]
  if i > 1 and i % 2 == 0:
    q.appendleft(a)
  else:
    q.append(a)

if N % 2 == 0:
  q.reverse()
print(" ".join(map(str, q)))
