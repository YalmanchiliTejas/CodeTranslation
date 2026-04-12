n = int(input())
a = list(map(int, input().split()))
m = 1000000007
sum = sum(a)
count = 0
for i in range(n-1):
  sum -= a[i]
  count += a[i]*sum
  count %= m
print(count)