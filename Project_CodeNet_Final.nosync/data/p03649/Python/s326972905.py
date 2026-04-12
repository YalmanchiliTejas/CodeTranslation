n = int(input())
A = list(map(int, input().split()))
m = min(A)
cnt = 0
while max(A) >= n:
  temp = 0
  for i in range(n):
    t = (A[i]+1)//(n+1)
    temp += t
    A[i] -= t*(n+1)
  for i in range(n):
    A[i] += temp
  cnt += temp
print(cnt)