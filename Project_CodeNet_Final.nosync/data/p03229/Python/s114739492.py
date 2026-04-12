N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
ans = 0
if N % 2 == 0:
  l = A[:N//2]
  h = A[N//2:]
  for i,j in zip(l, h):
    ans += (j - i) * 2 
  ans = ans - h[0] + l[-1]
else:
  l = A[:N//2]
  h = A[N//2+1:]
  m = A[N//2]
  for i,j in zip(l, h):
    ans += (j - i) * 2 
  ans = max(ans - h[0] + m, ans + l[-1] - m)
print(ans)