N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7

sum1 = 0
sum2 = 0
for a in A:
  sum1 = (sum1 + a)
  sum2 = (sum2 + a**2)

answer = ((sum1**2 - sum2) // 2) % mod
print(answer)