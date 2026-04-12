N = int(input())
A = list(map(int, input().split()))
if max(A) < N:
  print(0)
  quit()

ans = 0
while max(A) >= N:
  times = [0] * N
  for i, a in enumerate(A):
    t = -(-(a - (N-1))//N)
    A[i] -= t*N
    times[i] = t
  total = sum(times)
  ans += total
  for i in range(N):
    A[i] += total - times[i]

print(ans)