n = int(input())
a = list(map(int, input().split()))

z = 0
for i in range(n):
    z += a[i]
e = z % 2

y = (z ** 2) % 2000000014

x = 0
for j in range(n):
    x += a[j] ** 2
    x = x % 2000000014

w = int(((y - x) / 2) % 1000000007)
print(w)