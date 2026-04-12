def hersCode(L, n):
  ok = len(L)
  ng = -1
  while abs(ok - ng) > 1:
    mid = abs(ok + ng) // 2
    if L[mid] < n:
      ok = mid
    else:
      ng = mid
  return ok


N = int(input())
A = [int(input()) for _ in range(N)]

L = [-1]
for i in range(N):
  t = hersCode(L, A[i])
  if t == len(L) - 1:
    L[-1] = A[i]
    L.append(-1)
  else:
    L[t] = A[i]

print(len(L) - 1)