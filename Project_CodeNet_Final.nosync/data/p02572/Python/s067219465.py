n = int(input())
a = list(map(int,input().split()))
sum_a = sum(a)
result = 0
for i in range(n):
  result += a[i] * (sum_a - a[i])
print((result)//2 %(10**9+7))