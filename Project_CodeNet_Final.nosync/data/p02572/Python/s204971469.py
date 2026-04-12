N = int(input())
A = list(map(int,input().split()))
s = sum(A)
MOD = 10 ** 9 + 7

ans = 0
for i in A:
  s -= i
  ans += i * s

  
print(ans % MOD)