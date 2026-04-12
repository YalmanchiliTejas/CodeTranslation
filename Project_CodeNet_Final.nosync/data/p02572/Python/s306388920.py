n = int(input())
a = list(map(int, input().split()))
a.sort()

n_sum = a[0]
sum = 0
for i in range(1,n):
  sum += a[i] * n_sum
  n_sum += a[i]
print(sum % (10**9 + 7))

