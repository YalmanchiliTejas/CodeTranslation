N = int(input())
A = list(map(int,input().split()))
MOD = 10**9 + 7

ans = 0
for i in range(N):
  ans += A[i]

dig = 0
for i in range(N):
  dig += (A[i] ** 2 % MOD)
  
ans = (ans**2 - dig) % MOD

if ans % 2 == 0:
  print(ans // 2)
else:
  print((ans + MOD) //2)