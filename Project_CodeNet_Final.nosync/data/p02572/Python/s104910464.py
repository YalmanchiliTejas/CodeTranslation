n = int(input())
a = [int(e) for e in input().split()]

s = sum(a)

r = 0
for i in range(n):
    s -= a[i]
    r += a[i] * s
    r %= 10 ** 9 + 7

print(r)