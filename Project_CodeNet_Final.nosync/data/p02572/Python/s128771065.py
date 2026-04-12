mod = 10**9+7
N = int(input())
a = list(map(int, input().split()))
sum_a = 0
sum_a2 = 0
for x in a:
  sum_a += x
  sum_a2 += x**2

ans = ((sum_a**2 - sum_a2))//2
print(ans%mod)
