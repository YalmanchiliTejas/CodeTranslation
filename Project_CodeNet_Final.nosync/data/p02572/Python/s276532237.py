n = int(input())
a = list(map(int, input().split()))

sum = 0
for i in range(n):
    sum += a[i]

res = 0
s = sum
for i in range(n):
    s -= a[i]
    res = (res + s*a[i])%(10**9+7)
print(res)