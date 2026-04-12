n = int(input())
a = list(map(int, input().split()))
p = 10 ** 9 + 7

y = 0
for i in range(n):
    y += a[i]
    y = y % (2 * p)
x = (y ** 2) % (2 * p)

w = 0
for i in range(n):
    w += ((a[i] ** 2) % (2 * p))
    w = w % (2 * p)

z = ((x - w) / 2) % p
print(int(z))