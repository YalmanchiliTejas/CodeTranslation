n = int(input())
a = list(map(int, input().split()))
sum1 = sum(a)
sum2 = 0
for i in range(n):
  sum2 += a[i] ** 2
sum3 = (sum1 * sum1 - sum2) // 2
print(sum3 % (10**9+7))