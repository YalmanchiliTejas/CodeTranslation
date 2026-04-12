N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7
ak = 0
ak_2 = 0

for i in range(N):
  ak += A[i]
  ak_2 += A[i] ** 2
s = int(((ak ** 2) - ak_2) // 2)
print(s % mod)