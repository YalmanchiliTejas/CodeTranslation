N = int(input())
A = list(map(int, input().split()))
INF = 10 ** 9 + 7
s = A[0] * A[1] % INF
tmp = A[0]
for n in range(2,N):
  tmp += A[n-1] % INF
  s = (s + A[n] * tmp) % INF
print(s)