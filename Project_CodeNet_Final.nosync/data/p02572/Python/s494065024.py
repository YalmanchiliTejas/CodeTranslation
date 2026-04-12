n = int(input())
a = list(map(int, input().split()))
sum_a = 0
result = 0
for i in range(n):
  sum_a += a[i]
for j in range(n):
  sum_a -= a[j]
  result += sum_a * a[j]
print(result % (10**9 + 7))