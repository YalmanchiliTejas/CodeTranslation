N = int(input())

A = list(map(int, input().split()))

S = 0
for i in range(N):
  S += A[i]

c = S
d = 0
for j in range(N):
  c -= A[j]
  c = c%(10**9+7)
  d += A[j]*c
  d = d%(10**9+7)
  
print(d)